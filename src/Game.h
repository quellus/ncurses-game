#ifndef Game_H_Include
#define Game_H_Include

#include <ncurses.h>
#include <math.h>
#include "Direction.h"
#include "Player.h"
#include "Enemy.h"

class Game {
private:
	int maxx = 100;
	int maxy = 100;
	Player player = Player();
	Enemy enemy = Enemy(0, 25);
	char* stringToPrint;
	char map[100][101];
	WINDOW* window;

public:
	Game() {};
	void startGameLoop();
	void gameLoop();
	void printMap();
	void updateEnemyPosition();
	void drawEnemyOnMap();
	void drawPlayerOnMap();
	bool keyboardInput(int charCode);

};

#endif
