#include <iostream>
#include <vector>
#include <limits>
using namespace std;

const char PLAYER = 'X'; // Human player
const char AI = 'O';     // Computer (AI) player
const char EMPTY = ' ';  // Empty cell on the board

// Display the current state of the board
void displayBoard(const vector<vector<char>> &board)
{
    for (const auto &row : board)
    {
        for (int j = 0; j < row.size(); j++)
        {
            cout << row[j];
            if (j < row.size() - 1)
                cout << " | ";
        }
        cout << endl;
        cout << "---------" << endl;
    }
}

// Check for a win or draw
char checkWinner(const vector<vector<char>> &board)
{
    for (int i = 0; i < 3; ++i)
    {
        // Check rows
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != EMPTY)
            return board[i][0];
        // Check columns
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != EMPTY)
            return board[0][i];
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != EMPTY)
        return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != EMPTY)
        return board[0][2];
    // No winner, check if board is full (draw)
    for (const auto &row : board)
        for (char cell : row)
            if (cell == EMPTY)
                return EMPTY; // No winner, game is ongoing
    return 'D';               // Draw
}

// Minimax algorithm
int minimax(vector<vector<char>> &board, bool isMaximizing)
{
    char winner = checkWinner(board);
    if (winner == AI)
        return 10; // AI win
    if (winner == PLAYER)
        return -10; // Player win
    if (winner == 'D')
        return 0; // Draw

    int bestScore = isMaximizing ? numeric_limits<int>::min() : numeric_limits<int>::max();

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (board[i][j] == EMPTY)
            {
                board[i][j] = isMaximizing ? AI : PLAYER;
                int score = minimax(board, !isMaximizing);
                board[i][j] = EMPTY;
                bestScore = isMaximizing ? max(score, bestScore) : min(score, bestScore);
            }
        }
    }
    return bestScore;
}

// AI's best move calculation using minimax
pair<int, int> bestMove(vector<vector<char>> &board)
{
    int bestScore = numeric_limits<int>::min();
    pair<int, int> move = {-1, -1};

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (board[i][j] == EMPTY)
            {
                board[i][j] = AI;
                int score = minimax(board, false);
                board[i][j] = EMPTY;
                if (score > bestScore)
                {
                    bestScore = score;
                    move = {i, j};
                }
            }
        }
    }
    return move;
}

int main()
{
    vector<vector<char>> board(3, vector<char>(3, EMPTY));

    while (true)
    {
        int row, col;
        displayBoard(board);

        // Human player move
        cout << "Enter your move (row and column): ";
        cin >> row >> col;
        if (board[row][col] == EMPTY)
        {
            board[row][col] = PLAYER;
        }
        else
        {
            cout << "Invalid move. Try again.\n";
            continue;
        }

        // Check if the human player has won or if it’s a draw
        if (checkWinner(board) == PLAYER)
        {
            displayBoard(board);
            cout << "Congratulations! You won!\n";
            break;
        }
        else if (checkWinner(board) == 'D')
        {
            displayBoard(board);
            cout << "It's a draw!\n";
            break;
        }

        // Computer (AI) move
        pair<int, int> aiMove = bestMove(board);
        int aiRow = aiMove.first;
        int aiCol = aiMove.second;
        board[aiRow][aiCol] = AI;
        cout << "AI placed O at position: " << aiRow << ", " << aiCol << endl;

        // Check if the AI has won or if it’s a draw
        if (checkWinner(board) == AI)
        {
            displayBoard(board);
            cout << "AI wins! Better luck next time.\n";
            break;
        }
        else if (checkWinner(board) == 'D')
        {
            displayBoard(board);
            cout << "It's a draw!\n";
            break;
        }
    }
    return 0;
}
