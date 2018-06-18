//
// Created by luyi on 18-6-18.
//
#include "Player.h"

const std::regex digit_reg("^[0-9]+$");
Player::Player(int _player_id, int board_size) {
    player_id = _player_id;
    for (int i=0; i<board_size; i++) {
        for (int j=0; j<board_size; j++) {
            connection.push_back(i*board_size+j);
        }
    }
}

//do the union part of union-find algorithm
void Player::union_connection(int a, int b) {
    //union nodes with index a and index b
    int pre = connection.at(a);
    int post = connection.at(b);
    for (int i=0; i<connection.size(); i++) {
        if (connection.at(i) == pre)
            connection.at(i) = post;
    }
}

void Player::set_move(int x, int y, Board &board) {
    int index = board.xy2index(x, y);
    board.empty_slots.erase(index);
    //set move
    board.moves.at(x * board.board_size + y) = player_id;
    //implementation of union
    //upper left conner
    if (x == 0 && y == 0) {
        if (board.moves.at(index + 1) == player_id) {
            union_connection(connection.at(index), connection.at(index + 1));
        }
        if (board.moves.at(board.board_size + index) == player_id) {
            union_connection(connection.at(index), connection.at(board.board_size + index));
        }
    }
        //upper right conner
    else if (x == 0 && y == index - 1) {
        if (board.moves.at(index - 1) == player_id) {
            union_connection(connection.at(index), connection.at(index - 1));
        }
        if (board.moves.at(index + board.board_size - 1) == player_id) {
            union_connection(connection.at(index), connection.at(index + board.board_size - 1));
        }
        if (board.moves.at(index + board.board_size) == player_id) {
            union_connection(connection.at(index), connection.at(index + board.board_size));
        }
    }
        //lower left conner
    else if (x == board.board_size - 1 && y == 0) {
        if (board.moves.at(index + 1) == player_id) {
            union_connection(connection.at(index), connection.at(index + 1));
        }
        if (board.moves.at(index - board.board_size) == player_id) {
            union_connection(connection.at(index), connection.at(index - board.board_size));
        }
        if (board.moves.at(index - board.board_size + 1) == player_id) {
            union_connection(connection.at(index), connection.at(index - board.board_size + 1));
        }
    }
        //lower right conner
    else if (x == board.board_size - 1 && y == board.board_size - 1) {
        if (board.moves.at(board.board_size * board.board_size - 2) == player_id) {
            union_connection(connection.at(index), connection.at(board.board_size * board.board_size - 2));
        }
        if (board.moves.at((board.board_size - 2) * board.board_size) == player_id) {
            union_connection(connection.at(index), connection.at((board.board_size - 1) * board.board_size - 1));
        }
    }
        //left edge
    else if (y == 0) {
        if (board.moves.at(board.board_size * x + 1) == player_id) {
            union_connection(connection.at(index), connection.at(board.board_size * x + 1));
        }
        if (board.moves.at(board.board_size * (x - 1)) == player_id) {
            union_connection(connection.at(index), connection.at(board.board_size * (x - 1)));
        }
        if (board.moves.at(board.board_size * (x - 1) + 1) == player_id) {
            union_connection(connection.at(index), connection.at(board.board_size * (x - 1) + 1));
        }
        if (board.moves.at(board.board_size * (x + 1)) == player_id) {
            union_connection(connection.at(index), connection.at(board.board_size * (x + 1)));
        }
    }
        //right edge
    else if (y == board.board_size - 1) {
        if (board.moves.at(index - 1) == player_id) {
            union_connection(connection.at(index), connection.at(index - 1));
        }
        if (board.moves.at(index + board.board_size) == player_id) {
            union_connection(connection.at(index), connection.at(index + board.board_size));
        }
        if (board.moves.at(index + board.board_size - 1) == player_id) {
            union_connection(connection.at(index), connection.at(index + board.board_size - 1));
        }
        if (board.moves.at(index - board.board_size) == player_id) {
            union_connection(connection.at(index), connection.at(index - board.board_size));
        }
    }
        //top edge
    else if (x == 0) {
        if (board.moves.at(index - 1) == player_id) {
            union_connection(connection.at(index), connection.at(index - 1));
        }
        if (board.moves.at(index + 1) == player_id) {
            union_connection(connection.at(index), connection.at(index + 1));
        }
        if (board.moves.at(index + board.board_size) == player_id) {
            union_connection(connection.at(index), connection.at(index + board.board_size));
        }
        if (board.moves.at(index + board.board_size - 1) == player_id) {
            union_connection(connection.at(index), connection.at(index + board.board_size - 1));
        }
    }
        //bottom edge
    else if (x == board.board_size - 1) {
        if (board.moves.at(index - 1) == player_id) {
            union_connection(connection.at(index), connection.at(index - 1));
        }
        if (board.moves.at(index + 1) == player_id) {
            union_connection(connection.at(index), connection.at(index + 1));
        }
        if (board.moves.at(index - board.board_size) == player_id) {
            union_connection(connection.at(index), connection.at(index - board.board_size));
        }
        if (board.moves.at(index - board.board_size + 1) == player_id) {
            union_connection(connection.at(index), connection.at(index - board.board_size + 1));
        }
    }
        //middle part
    else {
        if (board.moves.at(index - 1) == player_id) {
            union_connection(connection.at(index), connection.at(index - 1));
        }
        if (board.moves.at(index + 1) == player_id) {
            union_connection(connection.at(index), connection.at(index + 1));
        }
        if (board.moves.at(index - board.board_size) == player_id) {
            union_connection(connection.at(index), connection.at(index - board.board_size));
        }
        if (board.moves.at(index - board.board_size + 1) == player_id) {
            union_connection(connection.at(index), connection.at(index - board.board_size + 1));
        }
        if (board.moves.at(index + board.board_size) == player_id) {
            union_connection(connection.at(index), connection.at(index + board.board_size));
        }
        if (board.moves.at(index + board.board_size - 1) == player_id) {
            union_connection(connection.at(index), connection.at(index + board.board_size - 1));
        }
    }
}
    
void Player::human_play(Board &board) {
    bool set = false;
    int x, y;
    while (!set) {
        //ask for user input
        std::string inputx, inputy;
        std::cout << "Please select x: ";
        std::cin >> inputx;
        std::cout << "Please select y: ";
        std::cin >> inputy;
        //detect if a given input is a number
        if (std::regex_search(inputx, digit_reg) && std::regex_search(inputy, digit_reg)) {
            x = std::stoi(inputx);
            y = std::stoi(inputy);
        }
        //check if a move is valid
        if (board.is_valid(x, y)) {
            set_move(x,y, board);
            set = true;
        }
        else {
            std::cout << "wrong move..." << std::endl;
        }
    }
}

void Player::random_move(Board &board) {
    int rand_idx = rand() % board.empty_slots.size();
    std::set<int>::iterator it = board.empty_slots.begin();
    std::advance(it, rand_idx);
    int random_pos = *it;
    std::pair<int,int> xy = std::make_pair(random_pos/board.board_size, random_pos%board.board_size);
    set_move(xy.first, xy.second, board);
}