#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>

#include "player.hpp"
#include "GameBoard.hpp"
#include "Menu.hpp"
#include "Victoire.hpp"

int main() {
    
    srand(static_cast<unsigned int>(time(0)));

    
    std::array<char, 9> board = {'1','2','3','4','5','6','7','8','9'};

    
    int choice = display_menu();

   
    Player player1 = create_player();
    Player player2;

    bool vsAI = false;

    if(choice == 1) {
        
        player2 = create_player();
    }
    else {
        
        vsAI = true;
        player2.name = "IA";
        player2.symbol = (player1.symbol == 'X') ? 'O' : 'X';
    }

    int turn = 0;
    bool gameOver = false;

    
    while(turn < 9 && !gameOver) {
        draw_game_board(board);

        
        Player* currentPlayer;

        if(turn % 2 == 0)
            currentPlayer = &player1;
        else
            currentPlayer = &player2;

        
        if(vsAI && currentPlayer->name == "IA") {
            std::cout << "L'IA joue...\n";
            play_ai(board, currentPlayer->symbol);
        }
        else {
            int move;
            do {
                std::cout << currentPlayer->name
                          << " (" << currentPlayer->symbol
                          << ") choisissez une case : ";
                std::cin >> move;
            } while(move < 1 || move > 9 ||
                    board[move - 1] == 'X' ||
                    board[move - 1] == 'O');

            board[move - 1] = currentPlayer->symbol;
        }

        // Vérification de la victoire
        if(check_win(board, currentPlayer->symbol)) {
            draw_game_board(board);
            std::cout << currentPlayer->name << " a gagné !\n";
            gameOver = true;
        }

        turn++;
    }

   
    if(!gameOver) {
        draw_game_board(board);
        std::cout << "Match nul !\n";
    }

    return 0;
}
