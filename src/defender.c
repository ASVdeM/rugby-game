// Standard headers
#include <stdio.h>
#include <stdlib.h>

// Internal headers
#include "direction.h"
#include "position.h"
#include "spy.h"
#include "auxiliar.h"

// Main header
#include "defender.h"

// Macros
#define UNUSED(x) (void)(x) // Auxiliary to avoid error of unused parameter

/*----------------------------------------------------------------------------*/
/*                              PUBLIC FUNCTIONS                              */
/*----------------------------------------------------------------------------*/

direction_t execute_defender_strategy(
	position_t defender_position, Spy attacker_spy){
  //Estratégia: Antes dos dois turnos, eu vou para cima e para baixo com probabilidade 50%. Depois, uso o espião e recalculo a probabilidade.
  static int rounds = 0;
  static double probability = 0.5;
  //a probabilidade de ir para cima é esta, a de ir pra baixo é 1 - esta.
  static position_t previous_position = INVALID_POSITION;
  static direction_t direction;

  if (equal_positions (previous_position, defender_position)){
    direction = random_direction (direction);
  }
  else {
    if (rounds > 2 && get_spy_number_uses (attacker_spy) > 0){
      position_t attacker_position = get_spy_position (attacker_spy);
      int height_difference = defender_position.i - attacker_position.i;
      if (height_difference != 0){
		probability += -height_difference*0.15;
      }
/*
      if (height_difference > 0){
        //o atacante está em baixo
        probability -= 0.15;
      }
      else if (height_difference < 0){
        probability += 0.15;
      }
*/
    }
    if (rand ()/(double) RAND_MAX < probability){
      direction = (direction_t) DIR_UP;
    }
    else{
      direction = (direction_t) DIR_DOWN;
    }
  }    
  rounds++;
  previous_position = defender_position;
  return direction;
}

/*----------------------------------------------------------------------------*/
