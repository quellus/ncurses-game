#ifndef Enemies_H_Include
#define Enemies_H_Include

#include "Enemy.h"
#include "EntityFactory.h"

class Enemies {
private:
	int enemyCount = 5;

public:
	Enemy enemies[5];
	void spawnEnemies();
	void moveEnemies();
};

#endif

