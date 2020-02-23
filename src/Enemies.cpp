#include "Enemies.h"

void Enemies::spawnEnemies() {
	EntityFactory enemyFactory = EntityFactory();
	for (int i = 0; i < enemyCount; i++) {
		enemies[i] = enemyFactory.spawnEnemy();
	}
}

void Enemies::moveEnemies() {
	for (int i = 0; i < enemyCount; i++) {
		enemies[i].move();
	}
}

