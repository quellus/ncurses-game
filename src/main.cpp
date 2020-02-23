#include "Game.h"
#include <iostream>

int main() {
	Game g = Game();
	unsigned long lastTickTimeMilli = std::chrono::system_clock::now().time_since_epoch() / std::chrono::milliseconds(1);

  
	while(true) {
    unsigned long currentTimeMilli = std::chrono::system_clock::now().time_since_epoch() / std::chrono::milliseconds(1);
    if (currentTimeMilli - lastTickTimeMilli >= 20) {
      g.update();
      lastTickTimeMilli = std::chrono::system_clock::now().time_since_epoch() / std::chrono::milliseconds(1);
    }
  }

	return 0;
}
