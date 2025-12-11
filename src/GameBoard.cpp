#include <iostream>
#include "GameBoard.hpp"

void draw_game_board(const std::array<char, 9>& board) {
    for (size_t i = 0; i < board.size(); i++) {
        std::cout << "| " << board[i] << " ";
        if ((i + 1) % 3 == 0) std::cout << "|\n";
    }
}
