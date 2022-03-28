// Standard headers
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Internal headers
#include "direction.h"
#include "position.h"
#include "spy.h"
#include "auxiliar.h"

// Main header
#include "attacker.h"

// Macros
#define UNUSED(x) (void)(x) // Auxiliary to avoid error of unused parameter

/*----------------------------------------------------------------------------*/
/*                              PUBLIC FUNCTIONS                              */
/*----------------------------------------------------------------------------*/

direction_t execute_attacker_strategy(
    position_t attacker_position, Spy defender_spy) {
  //Estratégia: Após 2 turnos, Eu uso o espião para Ver aonde está O Defensor E Daí eu vou na Direção Oposta (Direita e Acima Se Ele estiver abaixo, Direita E Abaixo se Estiver Acima, E Aleatório se estiver na Mesma altura)
  static position_t previous_position = INVALID_POSITION;
  static direction_t direction;
  static int rounds = 0;
  if (equal_positions (previous_position, attacker_position)){
    direction = random_direction (direction);
  }
  else {
    if (rounds > 2){
      if (get_spy_number_uses (defender_spy) > 0) {
        position_t defender_position = get_spy_position (defender_spy);
        int height_difference = attacker_position.i - defender_position.i;
	    if (height_difference != 0){
	      direction = (direction_t) {-height_difference, 1};
	    }
        else{
	      direction = (direction_t) {power (-1, rand () % 2), 1};
        }
      }
    }
    else {
      direction = (direction_t) DIR_RIGHT;
    }
  }
  rounds++;
  previous_position = attacker_position;
  return direction;
}

/*----------------------------------------------------------------------------*/
