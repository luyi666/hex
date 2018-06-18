//
// Created by luyi on 18-6-18.
//
#include "Game.h"
#include "Game.cpp"

const std::regex digit_reg("^[0-9]+$");

int main() {
    int board_size = 5;
    Game game(board_size);
    game.start();
}