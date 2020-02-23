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
private:
	int maxx = 100;
	int maxy = 100;
	Player player = Player();
	Enemy enemy = EntityFactory().spawnEnemy();
  Enemies enemies;
	int enemyCount = 5;
	char* stringToPrint;
	char map[100][101];
	WINDOW* window;

public:
	Game();
  ~Game();
	void update();
	void printMap();
	void updateEnemyPosition();
	void drawEnemyOnMap();
	void drawEnemiesOnMap();
	void drawPlayerOnMap();
	bool keyboardInput(int charCode);
};

#endif

