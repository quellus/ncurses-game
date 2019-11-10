#include "Enemy.h"

void Enemy::move(Direction direction) {
	switch(direction) {
		case Direction::left:
			posX--;
	}
}
