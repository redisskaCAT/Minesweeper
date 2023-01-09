cmake_minimum_required(VERSION 3.16)

project(minesweeper)

set(CMAKE_CXX_STANDARD 11)

     
include_directories(include)


add_executable(
    minesweeper /
    src/Minesweeper.cpp /
    src/ConsoleDisplay.cpp /
    src/CppSweeper.cpp /
    src/Field.cpp /
    src/GameControl.cpp /
    src/Menu.cpp /
    src/Mines.cpp /
    src/Minesweeper.cpp /
    src/Record.cpp /
    src/Timer.cpp /
)
