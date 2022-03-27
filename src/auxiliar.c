#include <stdlib.h>
#include "auxiliar.h"
direction_t random_direction (){
	int x = (rand () % 3) - 1,
	    y = (rand () % 3) - 1;
	while (x == 0 && y == 0){
		x = (rand () % 3) - 1;
		y = (rand () % 3) - 1;
	}
	return (direction_t) {x, y};
}
