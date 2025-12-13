#include <iostream>
#include <array>
#include "GameBoard.hpp"

void draw_game_board (const std::array<char, 9>& board){
    for (size_t j{0}; j < board.size(); ++j) {
        std::cout << "| " << board[j] << " ";
        if ((j + 1) % 3 == 0) std::cout << "|\n";
    }


}
