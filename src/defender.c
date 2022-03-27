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
  UNUSED (attacker_spy);
  
  static position_t previous_position = INVALID_POSITION;
  static direction_t next_direction;
  
  if (equal_positions (defender_position, previous_position)){
    next_direction = random_direction ();
  }
  
  else {
    if (rand () % 2 == 0){
      next_direction = (direction_t) {1, 0};
    }
    else{
      next_direction = (direction_t) {-1, 0};
    }
  }
      
  previous_position = defender_position;
  return next_direction;
}

/*----------------------------------------------------------------------------*/
