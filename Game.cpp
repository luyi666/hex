//
// Created by luyi on 18-6-18.
//

#include "Game.h"
#include <iostream>

Game::Game(int _board_size) {
    board_size = _board_size;
    board = Board(_board_size);
    player1 = Player(P1, _board_size);
    player2 = Player(P2, _board_size);
}

void Game::start() {
    board.draw_board();
    while (!ending) {
        player1.human_play(board);
        //stop if the game ends
        if (win(player1)) {
            ending = true;
            board.draw_board();
            std::cout << "you win!" << std::endl;
        }
        //AI move
        player2.random_move(board);
        if (win(player2)) {
            ending = true;
            board.draw_board();
            std::cout << "you lose!" << std::endl;
        }
        if (!ending)
            board.draw_board();
    }
}

bool Game::win(Player &player) {
    if (player.player_id==P1) {
        for (int i=0; i< board_size; i++) {
            for (int j=0; j< board_size; j++) {
                if (player.connection.at(i) == player.connection.at(board_size*board_size-j-1))
                    return true;
            }
        }
        return false;
    }
    if (player.player_id==P2) {
        for (int i=0; i<board_size; i++) {
            for (int j=0; j<board_size; j++) {
                if (player.connection.at(i*board_size) == player.connection.at(j*board_size+board_size-1))
                    return true;
            }
        }
        return false;
    }
}