//
// Created by luyi on 18-6-18.
//

#include "Board.h"
#include <regex>

#ifndef CPP_COURSE_PLAYER_H
#define CPP_COURSE_PLAYER_H


class Player {
private:
    std::vector<int> connection;
    int player_id;

    friend class Game;

public:
    Player() {};

    Player(int _player_id, int board_size);

    void union_connection(int a, int b);

    void set_move(int x, int y, Board &board);

    void human_play(Board &board);

    void random_move(Board &board);
};

#endif //CPP_COURSE_PLAYER_H
