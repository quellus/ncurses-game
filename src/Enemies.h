#ifndef Enemies_H_Include
#define Enemies_H_Include

#include "Enemy.h"
#include "EntityFactory.h"
#include <list>

class Enemies {
public:
  Enemies();
	void spawnEnemies(int count);
  void spawnNewEnemy();
	void moveEnemies();
  std::list<Enemy> getList();

private:
	std::list<Enemy> enemies;
};

#endif

