minesweeper: Mines.o Field.o Minesweeper.o Record.o Menu.o ConsoleDisplay.o Timer.o GameControl.o CppSweeper.cpp
	g++ -o minesweeper CppSweeper.cpp Mines.o Field.o Minesweeper.o Record.o Menu.o ConsoleDisplay.o Timer.o GameControl.o

Mines.o: Mines.h Mines.cpp
	g++ -c Mines.cpp -o Mines.o

Field.o: Field.h Field.cpp Mines.h
	g++ -c Field.cpp -o Field.o

Minesweeper.o: Minesweeper.h Minesweeper.cpp Field.h
	g++ -c Minesweeper.cpp -o Minesweeper.o

Record.o: Record.h Record.cpp
	g++ -c Record.cpp -o Record.o

Menu.o: Menu.h Menu.cpp
	g++ -c Menu.cpp -o Menu.o 

ConsoleDisplay.o: ConsoleDisplay.h ConsoleDisplay.cpp Field.h
	g++ -c ConsoleDisplay.cpp -o ConsoleDisplay.o
	
Timer.o: Timer.h Timer.cpp ConsoleDisplay.h
	g++ -c Timer.cpp -o Timer.o 

GameControl.o: GameControl.h GameControl.cpp Field.h Minesweeper.h Menu.h ConsoleDisplay.h Timer.h
	g++ -c GameControl.cpp -o GameControl.o
