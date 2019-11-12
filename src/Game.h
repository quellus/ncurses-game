#ifndef Game_H_Include
#define Game_H_Include

#include <ncurses.h>
#include <math.h>
#include "Direction.h"
#include "Player.h"
#include "Enemy.h"
#include "EntityFactory.h"

class Game {
private:
	int maxx = 100;
	int maxy = 100;
	Player player = Player();
	Enemy enemy = EntityFactory().spawnEnemy();
	int enemyCount = 5;
	Enemy enemies[5];
	char* stringToPrint;
	char map[100][101];
	WINDOW* window;

public:
	Game() {};
	void startGameLoop();
	void gameLoop();
	void spawnEnemies();
	void printMap();
	void updateEnemyPosition();
	void drawEnemyOnMap();
	void drawEnemiesOnMap();
	void drawPlayerOnMap();
	void moveEnemies();
	bool keyboardInput(int charCode);
};

#endif

