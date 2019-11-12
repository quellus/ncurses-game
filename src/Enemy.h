#ifndef Enemy_H_Include
#define Enemy_H_Include

#include "Direction.h"
#include "Entity.h"
#include <chrono>
#include <cstdlib>

class Enemy: public Entity {
private:
	unsigned long lastEnemyMoveTimeMilli = 0;
public:
	Enemy() {}
	Enemy(int posX, int posY) {this->posX = posX; this->posY = posY;}
	void setPosX(int posX) {this->posX = posX;}
	void move();
	void move(Direction direction);
	void move(int posX, int posY) {this->posX = posX; this->posY = posY;}
};

#endif
