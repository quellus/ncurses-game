#include "Game.h"

Game::Game() {
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
	enemies.spawnEnemies();
}

Game::~Game() {
	endwin();
}

void Game::update() {
  updateEnemyPosition();
  enemies.moveEnemies();
  printMap();
  drawEnemyOnMap();
  drawEnemiesOnMap();
  drawPlayerOnMap();

  int charCode = getch();
  if (charCode != ERR) {
    keyboardInput(charCode);
  }
}

void Game::printMap()  {
	for (int y = 0; y < maxy; y++) {
		mvwprintw(window, y, 0, map[y]);
	}
}

void Game::drawEnemiesOnMap() {
	for (int i = 0; i < enemyCount; i++) {
		Enemy currEnemy = enemies.enemies[i];
		mvwprintw(window, currEnemy.getPosY(), currEnemy.getPosX(), "x");
	}
}

void Game::updateEnemyPosition() {
  enemy.move();
}

void Game::drawEnemyOnMap() {
	mvwprintw(window, enemy.getPosY(), enemy.getPosX(), "x");
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

bool Game::keyboardInput(int charCode) {
	switch(charCode) {
    case 'k':
		case KEY_UP:
			player.move(Direction::up);
			break;

    case 'j':
		case KEY_DOWN:
			player.move(Direction::down);
			break;
			
    case 'h':
		case KEY_LEFT:
			player.move(Direction::left);
			break;

    case 'l':
		case KEY_RIGHT:
			player.move(Direction::right);
			break;
		default:
			return false;
	}
	return true;
}

