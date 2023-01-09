# Minesweeper
## Introduction
Minesweeper is a well-known game that many of us have played on the computer. 
The main goal of the game is to find mines on the field and mark them with flags. The game ends if all the mines have been marked, or if the player opens the cage under which the bomb is hiding. The minesweeper can make only once mistake.

The game starts at the moment when you click on one of the cells of the field. If you managed not to run into a mine, then a small area of the field opens around this cell, marked with numbers at the edges. 
The number X that opens in the cell implies that a bomb is hidden in X of the eight cells of the field surrounding it. If all except one of the cells with this numerical value are open around the cell, then an explosive object is waiting there.

## Showcase
<img src='https://github.com/redisskaCAT/minesweeper/blob/17c9536b9c550c64efea53426be3587486321cd8/gameplay.gif?raw=true'/>

## Installation
````
git clone https://github.com/redisskaCAT/Minesweeper
cd Minesweeper
bash setup.sh
build/minesweeper
````

## Features
The standard Minesweeper game implies a visual display of a field with mines and peaceful cells, the user's ability to interact with the field (open cells), informing the player about the win/loss, as well as displaying the number of undiscovered mines during the process.
This game also implements some additional features such as:

1. Storage of user data, possibility of registration/authorization, visualization of the game menu;

2. Table of records;

3. Multiple game levels:
- Rectangular field 10 by 10, number of minutes 10;
- Rectangular field 16 by 16, number of minutes 40;
- Rectangular field 30 by 16, number of minutes 99;
- A round field inscribed in a 15 by 15 square, number 25;
- A triangular field inscribed in a 19 by 19 square, number of minutes 30;

4. Field randomizer (new mined coordinates each time);

5. Moving around the playing field with arrows;

6. Timer (display of the elapsed time since the start of the game);

## Requirements
- Unix
- Git
- C++11 or higher
- Cmake
