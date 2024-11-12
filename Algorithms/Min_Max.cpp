#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// Minimax function to calculate the optimal value
int minimax(int depth, bool isMaximizingPlayer, const vector<vector<int>> &gameTree)
{
    // Base case: if we are at the leaf nodes, return the value
    if (depth == 0)
    {
        return gameTree[0][0]; // For simplicity, we use the first value in the vector
    }

    if (isMaximizingPlayer)
    {
        int best = numeric_limits<int>::min(); // Worst possible value for maximizing player

        // Loop through the children of the current node
        for (int i = 0; i < gameTree.size(); ++i)
        {
            int value = minimax(depth - 1, false, gameTree); // Call minimax recursively for minimizing player
            best = max(best, value);                         // Maximizing player chooses the max value
        }
        return best; // Return the best value for the maximizing player
    }
    else
    {
        int best = numeric_limits<int>::max(); // Worst possible value for minimizing player

        // Loop through the children of the current node
        for (int i = 0; i < gameTree.size(); ++i)
        {
            int value = minimax(depth - 1, true, gameTree); // Call minimax recursively for maximizing player
            best = min(best, value);                        // Minimizing player chooses the min value
        }
        return best; // Return the best value for the minimizing player
    }
}

int main()
{
    // Input: A simple game tree with leaf nodes already populated.
    // Here, the structure is 3 levels deep with the leaf nodes' values.

    // Level 0 (root)
    //            A
    //       /        \
    //    B            C
    //   /  \         /   \
    //  3    5       2     9

    vector<vector<int>> gameTree = {
        {3, 5, 2, 9} // Leaf nodes (values at depth = 0)
    };

    // Set the depth of the tree (3 levels)
    int depth = 3;
    bool isMaximizingPlayer = true; // Maximizing player starts first

    // Get the optimal value from the Minimax function
    int optimalValue = minimax(depth, isMaximizingPlayer, gameTree);

    cout << "The optimal value for the game is: " << optimalValue << endl;

    return 0;
}
