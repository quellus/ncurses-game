#ifndef Enemy_H_Include
#define Enemy_H_Include

#include "Direction.h"
#include "Entity.h"

class Enemy: public Entity {
public:
	void setPosX(int posX) {this->posX = posX;}
	void move(Direction direction);
	void move(int posX, int posY) {this->posX = posX; this->posY = posY;}
};

#endif
