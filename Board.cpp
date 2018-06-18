//
// Created by luyi on 18-6-18.
//
#include "Board.h"

Board::Board(int _board_size) {
    board_size = _board_size;
    for (int i=0; i<board_size; i++) {
        for (int j = 0; j < board_size; j++) {
            moves.push_back(Empty);
            empty_slots.insert(i*board_size+j);
        }
    }
}

int Board::xy2index(int x, int y) {
    return x*board_size+y;
}

void Board::draw_board() {
    //flush console output
    std::cout << std::flush;
    for (int i=0; i<board_size; i++) {
        for (int k=0; k<i; k++) {
            std::cout << "  ";
        }
        for (int j=0; j<board_size; j++) {
            if (moves.at(i*board_size+j)==Empty)
                std::cout << ".";
            else if (moves.at(i*board_size+j)==P1)
                std::cout << "X";
            else
                std::cout << "O";
            if (j!=board_size-1)
                std::cout << " - ";
        }
        std::cout << std::endl << " ";
        for (int k=0; k<i; k++) {
            std::cout << "  ";
        }
        if (i!=board_size-1) {
            std::cout << "\\ " << "";
            for (int j=0; j<board_size-1; j++) {
                std::cout << "/ " << "\\ ";
            }
            std::cout << std::endl;
        }
        else
            std::cout << std::endl;
    }
}

bool Board::is_valid(int x, int y) {
    if (x < 0 || y < 0 || x > board_size-1 || y > board_size-1 || moves.at(x*board_size+y) != 0) {
        return false;
    }
    return true;
}