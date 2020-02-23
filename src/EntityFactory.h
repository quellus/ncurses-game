#ifndef EntityFactory_H_Include
#define EntityFactory_H_Include

#include "Enemy.h"
#include "Player.h"

class EntityFactory {
public:
	Enemy spawnEnemy() {
		return Enemy(10, 10);
	}

	Player spawnPlayer() {
		return Player();
	}
};

#endif

