#ifndef EntityFactory_H_Include
#define EntityFactory_H_Include

#include "Enemy.h"
#include "Player.h"

class EntityFactory {
public:
	Enemy spawnEnemy() {
		return Enemy(0, 0);
	}

	Player spawnPlayer() {
		return Player();
	}
};

#endif

