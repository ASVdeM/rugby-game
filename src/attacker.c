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
#define random (rand () % 3) - 1 //isso dá um número inteiro entre -1 e 1 

/*----------------------------------------------------------------------------*/
/*                              PUBLIC FUNCTIONS                              */
/*----------------------------------------------------------------------------*/

direction_t execute_attacker_strategy(
    position_t attacker_position, Spy defender_spy) {
    UNUSED (defender_spy);
    srand (time (NULL));
    
    static position_t previous_position = INVALID_POSITION;
    static direction_t next_direction;
    
    if (equal_positions (previous_position, attacker_position)){
        next_direction = random_direction ();
    }
    else {
        next_direction = (direction_t) {random, 1};
    }
    
    previous_position = attacker_position;
    return next_direction;
}

/*----------------------------------------------------------------------------*/
