#include "auxiliar.h"

int sign (int x){
	return (x > 0) - (x < 0);
}
//visto em https://stackoverflow.com/a/1903975

int power (int x, int y){
	if (y == 0){
		return 1;
	}
	else {
		return x * power (x, y - 1);
	}
}

direction_t random_direction (direction_t forbidden_direction){
	//eu tentei andar e não consegui, daí eu sorteio uma direção aletória que não seja forbidden_direction
	unsigned int horizontal = rand () % 8, vertical = rand () % 8;
	vertical = (vertical - 2) % 8;//isso é necessário por causa do jeito que as direções funcionam
	direction_t next_direction = (direction_t) {sign (power (-1, horizontal/4) * (horizontal % 4)), sign (power (-1, vertical/4) * (vertical % 4))};
	while (next_direction.i != forbidden_direction.i && next_direction.j != forbidden_direction.j){
	next_direction = (direction_t) {sign (power (-1, horizontal/4) * (horizontal % 4)), sign (power (-1, vertical/4) * (vertical % 4))};
	}
	return next_direction;
}
