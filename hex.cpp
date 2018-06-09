//
// Created by luyi on 18-6-5.
//


#include "week4.hpp"
#include <iostream>

//draw board in console
void draw_slash() {
    std::cout << "\\ " << "";
    for (int j=0; j<board_size-1; j++) {
        std::cout << "/ " << "\\ ";
    }
    std::cout << std::endl;
}

//draw board in console
void draw_board(std::vector<int> moves) {
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
        if (i!=board_size-1)
            draw_slash();
        else
            std::cout << std::endl;
    }
}

//detect if a move is valid
bool pick(int x, int y, std::vector<int> &moves) {
    if (x < 0 || y < 0 || x > board_size-1 || y > board_size-1 || moves.at(x*board_size+y) != Empty) {
        return false;
    }
    return true;
}

//set move and unite related points
void set_move(int x, int y, Player &P, std::vector<int> &moves) {
    int index = xy2index(x,y);
    //set move
    moves.at(x*board_size+y) = P.player_id;
    //implementation of union
    //upper left conner
    if (x==0 && y==0) {
        if (moves.at(index+1)==P.player_id) {
            union_connection(P.connection, P.connection.at(index), P.connection.at(index+1));
        }
        if (moves.at(board_size+index)==P.player_id) {
            union_connection(P.connection, P.connection.at(index), P.connection.at(board_size+index));
        }
    }
    //upper right conner
    else if (x==0 && y==index-1) {
        if (moves.at(index-1)==P.player_id) {
            union_connection(P.connection, P.connection.at(index), P.connection.at(index-1));
        }
        if (moves.at(index+board_size-1)==P.player_id) {
            union_connection(P.connection, P.connection.at(index), P.connection.at(index+board_size-1));
        }
        if (moves.at(index+board_size)==P.player_id) {
            union_connection(P.connection, P.connection.at(index), P.connection.at(index+board_size));
        }
    }
    //lower left conner
    else if (x==board_size-1 && y == 0) {
        if (moves.at(index+1)==P.player_id) {
            union_connection(P.connection, P.connection.at(index), P.connection.at(index+1));
        }
        if (moves.at(index-board_size)==P.player_id) {
            union_connection(P.connection, P.connection.at(index), P.connection.at(index-board_size));
        }
        if (moves.at(index-board_size+1)==P.player_id) {
            union_connection(P.connection, P.connection.at(index), P.connection.at(index-board_size+1));
        }
    }
    //lower right conner
    else if (x==board_size-1 && y==board_size-1) {
        if (moves.at(board_size*board_size-2)==P.player_id) {
            union_connection(P.connection, P.connection.at(index), P.connection.at(board_size*board_size-2));
        }
        if (moves.at((board_size-2)*board_size)==P.player_id) {
            union_connection(P.connection, P.connection.at(index), P.connection.at((board_size-1)*board_size-1));
        }
    }
    //left edge
    else if (y==0) {
        if (moves.at(board_size*x+1)==P.player_id) {
            union_connection(P.connection, P.connection.at(index), P.connection.at(board_size*x+1));
        }
        if (moves.at(board_size*(x-1))==P.player_id) {
            union_connection(P.connection, P.connection.at(index), P.connection.at(board_size*(x-1)));
        }
        if (moves.at(board_size*(x-1)+1)==P.player_id) {
            union_connection(P.connection, P.connection.at(index), P.connection.at(board_size*(x-1)+1));
        }
        if (moves.at(board_size*(x+1))==P.player_id) {
            union_connection(P.connection, P.connection.at(index), P.connection.at(board_size*(x+1)));
        }
    }
    //right edge
    else if (y == board_size-1) {
        if (moves.at(index-1)==P.player_id) {
            union_connection(P.connection, P.connection.at(index), P.connection.at(index-1));
        }
        if (moves.at(index+board_size)==P.player_id) {
            union_connection(P.connection, P.connection.at(index), P.connection.at(index+board_size));
        }
        if (moves.at(index+board_size-1)==P.player_id) {
            union_connection(P.connection, P.connection.at(index), P.connection.at(index+board_size-1));
        }
        if (moves.at(index-board_size)==P.player_id) {
            union_connection(P.connection, P.connection.at(index), P.connection.at(index-board_size));
        }
    }
    //top edge
    else if (x == 0) {
        if (moves.at(index-1)==P.player_id) {
            union_connection(P.connection, P.connection.at(index), P.connection.at(index-1));
        }
        if (moves.at(index+1)==P.player_id) {
            union_connection(P.connection, P.connection.at(index), P.connection.at(index+1));
        }
        if (moves.at(index+board_size)==P.player_id) {
            union_connection(P.connection, P.connection.at(index), P.connection.at(index+board_size));
        }
        if (moves.at(index+board_size-1)==P.player_id) {
            union_connection(P.connection, P.connection.at(index), P.connection.at(index+board_size-1));
        }
    }
    //bottom edge
    else if (x == board_size-1) {
        if (moves.at(index-1)==P.player_id) {
            union_connection(P.connection, P.connection.at(index), P.connection.at(index-1));
        }
        if (moves.at(index+1)==P.player_id) {
            union_connection(P.connection, P.connection.at(index), P.connection.at(index+1));
        }
        if (moves.at(index-board_size)==P.player_id) {
            union_connection(P.connection, P.connection.at(index), P.connection.at(index-board_size));
        }
        if (moves.at(index-board_size+1)==P.player_id) {
            union_connection(P.connection, P.connection.at(index), P.connection.at(index-board_size+1));
        }
    }
    //middle part
    else {
        if (moves.at(index-1)==P.player_id) {
            union_connection(P.connection, P.connection.at(index), P.connection.at(index-1));
        }
        if (moves.at(index+1)==P.player_id) {
            union_connection(P.connection, P.connection.at(index), P.connection.at(index+1));
        }
        if (moves.at(index-board_size)==P.player_id) {
            union_connection(P.connection, P.connection.at(index), P.connection.at(index-board_size));
        }
        if (moves.at(index-board_size+1)==P.player_id) {
            union_connection(P.connection, P.connection.at(index), P.connection.at(index-board_size+1));
        }
        if (moves.at(index+board_size)==P.player_id) {
            union_connection(P.connection, P.connection.at(index), P.connection.at(index+board_size));
        }
        if (moves.at(index+board_size-1)==P.player_id) {
            union_connection(P.connection, P.connection.at(index), P.connection.at(index+board_size-1));
        }
    }
}


// generate a random move for AI player at this stage
void random_move(std::vector<int> &moves) {
    std::vector<int> empty_slots;
    for (int i=0; i<moves.size(); i++) {
        if (moves.at(i)==Empty)
            empty_slots.push_back(i);
    }
    int rand_idx = rand() % empty_slots.size();
    std::pair<int,int> xy = std::make_pair(empty_slots.at(rand_idx)/board_size, empty_slots.at(rand_idx)%board_size);
    set_move(xy.first, xy.second, computer, moves);
};

// ask for input and check if the move is valid
void human_play(std::vector<int> &moves) {
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
        if (pick(x, y, moves)) {
            set_move(x,y,human,moves);
            set = true;
        }
        else {
            std::cout << "wrong move..." << std::endl;
        }
    }
}

//detect if one of the players wins with union-find algorithm
bool win(Player P) {
    if (P.player_id==P1) {
        for (int i=0; i<board_size; i++) {
            for (int j=0; j<board_size; j++) {
                if (P.connection.at(i) == P.connection.at(board_size*board_size-j-1))
                    return true;
            }
        }
        return false;
    }
    if (P.player_id==P2) {
        for (int i=0; i<board_size; i++) {
            for (int j=0; j<board_size; j++) {
                if (P.connection.at(i*board_size) == P.connection.at(j*board_size+board_size-1))
                    return true;
            }
        }
        return false;
    }
}

//do the union part of union-find algorithm
void union_connection(std::vector<int> &connection, int a, int b) {
    //union nodes with index a and index b
    int pre = connection.at(a);
    int post = connection.at(b);
    for (int i=0; i<connection.size(); i++) {
        if (connection.at(i) == pre)
            connection.at(i) = post;
    }
}

//convert a coordinate to list index
int xy2index(int x,int y) {
    return x*board_size+y;
}

int main() {
    bool ending = false;
    std::vector<int> moves, connection1, connection2;
    for (int i=0; i<board_size; i++) {
        for (int j=0; j<board_size; j++) {
            moves.push_back(Empty);
            connection1.push_back(i*board_size+j);
            connection2.push_back(i*board_size+j);
        }
    }
    human.connection = connection1;
    human.player_id = P1;
    computer.connection = connection2;
    computer.player_id = P2;
    srand (time(NULL));
    draw_board(moves);
    while (!ending) {
        //human move
        human_play(moves);
        //stop if the game ends
        if (win(human)) {
            ending = true;
            draw_board(moves);
            std::cout << "you win!" << std::endl;
        }
        //AI move
        random_move(moves);
        if (win(computer)) {
            ending = true;
            draw_board(moves);
            std::cout << "you lose!" << std::endl;
        }
        if (!ending)
            draw_board(moves);
    }
}