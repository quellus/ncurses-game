#include "Game.h"

void Game::startGameLoop() {
	window = initscr();
	keypad(window, true);
	nodelay(window, true);
	for (int y = 0; y < maxy; y++) {
		for (int x = 0; x < maxx; x++) {
			map[y][x] = '.';
		}
		map[y][maxx] = 0;
	}
	cbreak();
	noecho();
	spawnEnemies();
	gameLoop();
	endwin();
}

void Game::gameLoop() {
	while(true) {
		updateEnemyPosition();
		moveEnemies();
		printMap();
		drawEnemyOnMap();
		drawEnemiesOnMap();
		drawPlayerOnMap();

		int charCode = getch();
		if (charCode != ERR) {
			keyboardInput(charCode);
		}
	}

}


void Game::spawnEnemies() {
	EntityFactory enemyFactory = EntityFactory();
	for (int i = 0; i < enemyCount; i++) {
		enemies[i] = enemyFactory.spawnEnemy();
	}
}

void Game::printMap()  {
	for (int y = 0; y < maxy; y++) {
		mvwprintw(window, y, 0, map[y]);
	}
}

void Game::updateEnemyPosition() {
  enemy.move();
}

void Game::drawEnemyOnMap() {
	mvwprintw(window, enemy.getPosY(), enemy.getPosX(), "x");
}

void Game::drawEnemiesOnMap() {
	for (int i = 0; i < enemyCount; i++) {
		Enemy currEnemy = enemies[i];
		mvwprintw(window, currEnemy.getPosY(), currEnemy.getPosX(), "x");
	}
}

void Game::drawPlayerOnMap() {
	const char* playerChar = "^";
	switch(player.getDirection()) {
		case Direction::up:
			playerChar = "^";
			break;
		case Direction::right:
			playerChar = ">";
			break;
		case Direction::down:
			playerChar = "v";
			break;
		case Direction::left:
			playerChar = "<";
			break;
	}
	mvwprintw(window, player.getPosY(), player.getPosX(), playerChar);
}

void Game::moveEnemies() {
	for (int i = 0; i < enemyCount; i++) {
		enemies[i].move();
	}
}

bool Game::keyboardInput(int charCode) {
	switch(charCode) {
		case KEY_UP:
			player.move(Direction::up);
			break;

		case KEY_DOWN:
			player.move(Direction::down);
			break;
			
		case KEY_LEFT:
			player.move(Direction::left);
			break;

		case KEY_RIGHT:
			player.move(Direction::right);
			break;
		default:
			return false;
	}
	return true;
}

