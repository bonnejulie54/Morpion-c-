#include "Victoire.hpp"

bool check_win(const std::array<char, 9>& board, const std::string& symbol) {
    char s = symbol[0];
    
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
