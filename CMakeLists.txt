cmake_minimum_required(VERSION 3.5.2)

project(minesweeper)

set(CMAKE_POLICY_DEFAULT_CMP0135 NEW)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror")

     
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
