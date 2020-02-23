#ifndef Entity_H_Include
#define Entity_H_Include

#include "Direction.h"

class Entity {
protected:
	int posX = 0;
	int posY = 0;
	Direction direction = Direction::up;

public:
	Entity() {}
	Entity(int posX, int posY) {this->posX = posX; this->posY = posY;}
  void setPosX(int newPosX) {posX = newPosX;}
  void setPosY(int newPosY) {posX = newPosY;}
	int getPosX() {return posX;}
	int getPosY() {return posY;}
	Direction getDirection() {return direction;}
	virtual void move(Direction direction) = 0;
};

#endif

