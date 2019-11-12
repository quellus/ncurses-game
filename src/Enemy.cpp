#include "Enemy.h"

void Enemy::move() {
		unsigned long currentTimeMilli = std::chrono::system_clock::now().time_since_epoch() / std::chrono::milliseconds(1);
	  if (currentTimeMilli - lastEnemyMoveTimeMilli >= 50) {
		if (posX <= 0) {
			posX = 99;
		} else {
			move(Direction::left);
		}
		lastEnemyMoveTimeMilli = currentTimeMilli;
	}
}

void Enemy::move(Direction direction) {
	switch(direction) {
		case Direction::left:
			posX--;
	}
}
