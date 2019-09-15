#include <ncurses.h>
#include <chrono>
#include <math.h>

class Game {
private:
	int maxx = 100;
	int maxy = 100;
	int playerPosy = 0;
	int playerPosx = 0;
	int playerDirection = 0;
	int enemyPosy = 25;
	int enemyPosx = 0;
	char* stringToPrint;
	char map[100][101];
	unsigned long currentTimeMilli;
	unsigned long lastEnemyMoveTimeMilli;
	WINDOW* window;

public:
	Game() {
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
		while(true) {
			currentTimeMilli = std::chrono::system_clock::now().time_since_epoch() / std::chrono::milliseconds(1);
			updateEnemyPosition();
			printMap();
			drawEnemyOnMap();
			drawPlayerOnMap();

			int charCode = getch();
			if (charCode != ERR) {
				keyboardInput(charCode);
			}
		}
		endwin();

	}

	void printMap()  {
		for (int y = 0; y < maxy; y++) {
			mvwprintw(window, y, 0, map[y]);
		}
	}

	void updateEnemyPosition() {
		//if (currentTimeMilli - lastEnemyMoveTimeMilli >= 100) {
			if (enemyPosx <= 0) {
				enemyPosx = 99;
			} else {
				enemyPosx--;
			}
		//}


		lastEnemyMoveTimeMilli = currentTimeMilli;
	}

	void drawEnemyOnMap() {
		//unsigned long delta = currentTimeMilli - lastEnemyMoveTimeMilli;
		//int n = log10(delta) + 1;
		//int i;
	        //char *numberArray = (char*) calloc(n, sizeof(char));
		//for ( i = 0; i < n; ++i, delta /= 10 )
		//{
		    //numberArray[i] = delta % 10;
		//}
		//numberArray[n -1] == '\0';
		//mvwprintw(window, 0,0, numberArray);
		//mvwprintw(window, 0, 0, "this should work");
		mvwprintw(window, enemyPosy, enemyPosx, "x");
	}

	void drawPlayerOnMap() {
		switch(playerDirection) {
			case 0:
				mvwprintw(window, playerPosy, playerPosx, "^");
				break;
			case 90:
				mvwprintw(window, playerPosy, playerPosx, ">");
				break;
			case 180:
				mvwprintw(window, playerPosy, playerPosx, "v");
				break;
			case 270:
				mvwprintw(window, playerPosy, playerPosx, "<");
				break;
		}
	}

	bool keyboardInput(int charCode) {
		switch(charCode) {
			case KEY_UP:
				playerPosy--;
				playerDirection = 0;
				stringToPrint = "Up";
				break;
			case KEY_DOWN:
				playerPosy++;
				playerDirection = 180;
				stringToPrint = "Down";
				break;
			case KEY_LEFT:
				playerPosx--;
				playerDirection = 270;
				stringToPrint = "Left";
				break;
			case KEY_RIGHT:
				playerPosx++;
				playerDirection = 90;
				stringToPrint = "Right";
				break;
		}
	}

	
};

int main() {
	Game();
	//initscr();		
	//printw("Hello World !!!");
	//while(true) {
		//continue;
	//}
	//getch();			
	//endwin();		

	return 0;
}
