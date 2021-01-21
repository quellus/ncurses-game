#include "Enemy.h"

void Enemy::move() {
  if (ticksSinceLastMove >= ticksBetweenMove) {
	if (posX <= 0) {
	  posX = 99;
	  posY = rand() % 50;
	} else {
	  move(Direction::left);
	}
	ticksSinceLastMove = 0;
  } else {
	ticksSinceLastMove++;
  }
}

void Enemy::move(Direction direction) {
  switch(direction) {
	case Direction::left:
	  posX--;
	  break;
	case Direction::right:
	  posX++;
	  break;
	case Direction::up:
	  posY--;
	  break;
	case Direction::down:
	  posY++;
	  break;
  }
}
