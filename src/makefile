OBJS = main.o Game.o Player.o Enemies.o Enemy.o
CF = -g -I. -Wall -c
EXE = ncurses-game.out

ncurses-game: $(OBJS)
	g++ $(OBJS) -Wall -o $(EXE) -lncurses 

main.o: main.cpp Game.h
	g++ main.cpp $(CF)

Game.o: Game.h Game.cpp Player.h Direction.h Enemies.h Enemy.h
	g++ Game.cpp $(CF) -lncurses

Enemies.o: Enemy.h
	g++ Enemies.cpp $(CF)

Enemy.o: Enemy.h Enemy.cpp Entity.h
	g++ Enemy.cpp $(CF)

Player.o: Player.h Player.cpp Direction.h Entity.h
	g++ Player.cpp $(CF)

clean:
	rm $(OBJS) $(EXE)
