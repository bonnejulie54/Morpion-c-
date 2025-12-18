#include "Victoire.hpp"

bool check_win(const std::array<char, 9>& board, char s) {
    if(board[0]==s && board[1]==s && board[2]==s) return true;
    if(board[3]==s && board[4]==s && board[5]==s) return true;
    if(board[6]==s && board[7]==s && board[8]==s) return true;

    if(board[0]==s && board[3]==s && board[6]==s) return true;
    if(board[1]==s && board[4]==s && board[7]==s) return true;
    if(board[2]==s && board[5]==s && board[8]==s) return true;

    if(board[0]==s && board[4]==s && board[8]==s) return true;
    if(board[2]==s && board[4]==s && board[6]==s) return true;

    return false;
}


void play_ai(std::array<char, 9>& board, char symbol) {
    char adversaire = (symbol == 'X') ? 'O' : 'X';

    int combosGagnant[8][3] = {
        {0,1,2}, {3,4,5}, {6,7,8}, 
        {0,3,6}, {1,4,7}, {2,5,8},
        {0,4,8}, {2,4,6}           
    };

    for(int i = 0; i < 8; i++) {
        int a = combosGagnant[i][0];
        int b = combosGagnant[i][1];
        int c = combosGagnant[i][2];

        if(board[a] == adversaire && board[b] == adversaire && board[c] != 'X' && board[c] != 'O') {
            board[c] = symbol;
            return;
        }
        if(board[a] == adversaire && board[c] == adversaire && board[b] != 'X' && board[b] != 'O') {
            board[b] = symbol;
            return;
        }
        if(board[b] == adversaire && board[c] == adversaire && board[a] != 'X' && board[a] != 'O') {
            board[a] = symbol;
            return;
        }
    }

    int index;
    do {
        index = rand() % 9;
    } while(board[index] == 'X' || board[index] == 'O');

    board[index] = symbol;
}
