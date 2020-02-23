#ifndef Enemies_H_Include
#define Enemies_H_Include

#include "Enemy.h"
#include "EntityFactory.h"
#include <list>

class Enemies {
private:
	std::list<Enemy> enemies;

public:
  Enemies();
	void spawnEnemies(int count);
  void spawnNewEnemy();
	void moveEnemies();
  std::list<Enemy> getList();
};

#endif

