//
// Created by luyi on 18-6-18.
//
#include "Board.h"
#include "Player.h"

#ifndef CPP_COURSE_GAME_H
#define CPP_COURSE_GAME_H

class Game {
private:
    Board board;
    Player player1;
    Player player2;
    enum Player_id {Empty, P1, P2};
    bool ending = false;
    int board_size;
public:
    Game(int _board_size);
    void start();
    bool win(Player &player);
};
#endif //CPP_COURSE_GAME_H
