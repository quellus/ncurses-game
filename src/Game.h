#ifndef Game_H_Include
#define Game_H_Include

#include <ncurses.h>
#include <math.h>
#include "Direction.h"
#include "Player.h"
#include "Enemies.h"
#include "Enemy.h"
#include "EntityFactory.h"

class Game {
public:
	Game();
  ~Game();
	void update();
	void printMap();
	void updateEnemyPosition();
  bool isPlayerCollision();
	void drawEnemyOnMap();
	void drawEnemiesOnMap();
	void drawPlayerOnMap();
	bool getKeyboardInputAndMovePlayer(int charCode);

private:
	int maxx = 100;
	int maxy = 100;
	Player player = Player();
	Enemy enemy = EntityFactory().spawnEnemy();
  Enemies enemies;
	char* stringToPrint;
	char map[100][101];
	WINDOW* window;
  unsigned int ticksSinceLastEnemySpawn = 0;
  unsigned int ticksBetweenEnemySpawn = 1000;
};

#endif

