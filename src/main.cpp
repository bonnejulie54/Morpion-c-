#include <iostream>
#include <array>
#include "GameBoard.hpp"
#include "player.hpp"
#include "Menu.hpp"
#include "Victoire.hpp"

bool check_win(const std::array<char, 9>& board, const std::string& symbol);

int main() {
    std::array<char, 9> board = { '1','2','3','4','5','6','7','8','9' };

    display_menu();

    Player player1 = create_player();
    Player player2 = create_player();

    
    int turn = 0;
    bool gameOver = false;
    while(turn < 9 && !gameOver) {
        draw_game_board(board);

        Player currentPlayer = (turn % 2 == 0) ? player1 : player2;

        int move;
        do {
            std::cout << currentPlayer.name << " (" << currentPlayer.symbol << "), entrez votre case : ";
            std::cin >> move;
        } while(move < 1 || move > 9 || board[move-1] == player1.symbol[0] || board[move-1] == player2.symbol[0]);

        board[move-1] = currentPlayer.symbol[0];

        
        if(check_win(board, currentPlayer.symbol)) {
            draw_game_board(board);
            std::cout << currentPlayer.name << " a gagné !\n";
            gameOver = true;
        }

        turn++;
    }

    if(!gameOver)
        std::cout << "Match nul !\n";

    return 0;
}
