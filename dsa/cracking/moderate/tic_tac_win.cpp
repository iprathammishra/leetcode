// 4. **Tic Tac Win:** Design an algorithm to figure out if someone has won a game of tic-tac-toe.
#include <iostream>
#include <vector>
bool checkWinner(const std::vector<std::vector<char>>& board, const char player)
{
    for (int i = 0; i < 3; ++i)
        if(
            (board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)
        )
            return true;
    if (
        (board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[2][0] == player && board[1][1] == player && board[0][2] == player)
        )
            return true;
    return false; 
}
bool gameOver(const std::vector<std::vector<char>>& board)
{
    for (int i = 0; i < 3; ++i)
        for(int j = 0; j < 3; ++j)
            if (board[i][j] == ' ')
                return false;
    return true;
}
int main()
{
     std::vector<std::vector<char>> board = {
        {'O', 'X', 'O'},
        {'O', 'X', 'X'},
        {'X', 'O', 'X'}
    };

    if (checkWinner(board, 'X')) {
        std::cout << "Player X has won!\n";
    } else if (checkWinner(board, 'O')) {
        std::cout << "Player O has won!\n";
    } else if (gameOver(board)) {
        std::cout << "It's a draw!\n";
    } else {
        std::cout << "The game is still in progress.\n";
    }
    return 0;
}