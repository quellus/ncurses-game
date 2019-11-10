#include "Player.h"

void Player::move(Direction direction) {
	this->direction = direction;
	switch(direction) {
		case Direction::up:
			posY--;
			break;
		case Direction::down:
			posY++;
			break;
		case Direction::left:
			posX--;
			break;
		case Direction::right:
			posX++;
			break;
	}

}
