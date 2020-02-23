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
  
  enemies.spawnEnemies(5);
}

Game::~Game() {
	endwin();
}

void Game::update() {
  if (ticksSinceLastEnemySpawn >= ticksBetweenEnemySpawn) {
    enemies.spawnNewEnemy();
    ticksSinceLastEnemySpawn  = 0;
  } else {
    ticksSinceLastEnemySpawn++;
  }
  updateEnemyPosition();
  enemies.moveEnemies();
  printMap();
  drawEnemyOnMap();
  drawEnemiesOnMap();
  drawPlayerOnMap();

  int charCode = getch();
  if (charCode != ERR) {
    getKeyboardInputAndMovePlayer(charCode);
  }
  
  if (isPlayerCollision()) {
    endwin();
    exit(0);
  }
}

void Game::printMap()  {
	for (int y = 0; y < maxy; y++) {
		mvwprintw(window, y, 0, map[y]);
	}
}

void Game::drawEnemiesOnMap() {
  std::list<Enemy>::iterator it;
  std::list<Enemy> enemiesList = enemies.getList();
  for (it = enemiesList.begin(); it != enemiesList.end(); ++it){
		mvwprintw(window, it->getPosY(), it->getPosX(), "x");
  }
	//for (int i = 0; i < enemies.enemyCount; i++) {
	//	Enemy currEnemy = enemies.enemies[i];
	//	mvwprintw(window, currEnemy.getPosY(), currEnemy.getPosX(), "x");
	//}
}

void Game::updateEnemyPosition() {
  enemy.move();
}


bool Game::isPlayerCollision() {
  std::list<Enemy>::iterator it;
  std::list<Enemy> enemiesList = enemies.getList();
  for (it = enemiesList.begin(); it != enemiesList.end(); ++it){
    if (it->getPosX() == player.getPosX() && it->getPosY() == player.getPosY()) {
      return true;
    }
  }
  return false;

  //for (int i = 0; i < enemies.enemyCount; i++) {
  //  Enemy currEnemy = enemies.enemies[i];
  //  if (currEnemy.getPosX() == player.getPosX() && currEnemy.getPosY() == player.getPosY()) {
  //    return true;
  //  }
  //}
  //return false;
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

bool Game::getKeyboardInputAndMovePlayer(int charCode) {
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

