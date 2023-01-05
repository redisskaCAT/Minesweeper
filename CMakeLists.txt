cmake_minimum_required(VERSION 3.16)

project(minesweeper)

set(CMAKE_CXX_STANDARD 17)

     
include_directories(include)


add_executable(
    minesweeper /
    files/Minesweeper.cpp /
    files/ConsoleDisplay.cpp /
    files/CppSweeper.cpp /
    files/Field.cpp /
    files/GameControl.cpp /
    files/Menu.cpp /
    files/Mines.cpp /
    files/Minesweeper.cpp /
    files/Record.cpp /
    files/Timer.cpp /
)
