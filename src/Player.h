#ifndef Player_H_Include
#define Player_H_Include

#include "Direction.h"
#include "Entity.h"

class Player: public Entity {

public:
	Player() {}
	void move(Direction direction);
};

#endif

