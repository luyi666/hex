//
// Created by luyi on 18-6-6.
//

#ifndef CPP_COURSE_WEEK4_H
#define CPP_COURSE_WEEK4_H

#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <tuple>
#include <string>
#include <regex>

const int board_size = 11;
const std::regex digit_reg("^[0-9]+$");
enum Player_id { Empty, P1, P2};

struct Player {
    int player_id;
    std::vector<int> connection;
};
Player computer, human;

void draw_slash();
void draw_board(std::vector<int> moves);
bool pick(int x, int y, std::vector<int> &moves);
void human_play(std::vector<int> &moves);
bool win(Player P);
void union_connection(std::vector<int> &connection, int a, int b);
int xy2index(int x, int y);

#endif //CPP_COURSE_WEEK4_H
