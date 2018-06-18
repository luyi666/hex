//
// Created by luyi on 18-6-18.
//
#include <vector>
#include <set>
#include <iostream>

#ifndef CPP_COURSE_BOARD_H
#define CPP_COURSE_BOARD_H

class Board {
private:
    int board_size;
    std::vector<int> moves;
    std::set<int> empty_slots;
    enum Player_id {
        Empty, P1, P2
    };

    friend class Player;

public:
    Board() {};

    Board(int _board_size);

    int xy2index(int x, int y);

    void draw_board();

    bool is_valid(int x, int y);
};

#endif //CPP_COURSE_BOARD_H
