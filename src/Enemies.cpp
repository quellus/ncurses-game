#include "Enemies.h"

Enemies::Enemies() {
}

void Enemies::spawnEnemies(int count) {
  EntityFactory entityFactory = EntityFactory();
  for (int i = 0; i < count; i++) {
	enemies.push_front(entityFactory.spawnEnemy());
  }
}

void Enemies::spawnNewEnemy() {
  EntityFactory entityFactory = EntityFactory();
  enemies.push_front(entityFactory.spawnEnemy());

}

void Enemies::moveEnemies() {
  std::list<Enemy>::iterator it;
  for (it = enemies.begin(); it != enemies.end(); ++it){
	it->move();
  }
}

std::list<Enemy> Enemies::getList() {
  return enemies;
}

