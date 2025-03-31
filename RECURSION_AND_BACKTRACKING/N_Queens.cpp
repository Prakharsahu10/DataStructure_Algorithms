/*

The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.



Example 1:


Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
Example 2:

Input: n = 1
Output: [["Q"]]


Constraints:

1 <= n <= 9

*/

class Solution
{
public:
    bool isSafe(vector<string> &board, int row, int col, int n)
    {
        // horizontal
        for (int j = 0; j < n; j++)
        {
            if (board[row][j] == 'Q')
            {
                return false;
            }
        }

        // vertical
        for (int i = 0; i < n; i++)
        {
            if (board[i][col] == 'Q')
            {
                return false;
            }
        }

        // left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        {
            if (board[i][j] == 'Q')
            {
                return false;
            }
        }

        // right diagonal
        for (int i = row, j = col; i >= 0 && j < n; i--, j++)
        {
            if (board[i][j] == 'Q')
            {
                return false;
            }
        }
        return true;
    }

    void nQueens(vector<string> &board, int row, int n,
                 vector<vector<string>> &ans)
    {

        if (row == n)
        {
            ans.push_back({board});
            return;
        }

        for (int j = 0; j < n; j++)
        {
            if (isSafe(board, row, j, n))
            {
                board[row][j] = 'Q';
                nQueens(board, row + 1, n, ans);
                board[row][j] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;

        nQueens(board, 0, n, ans);
        return ans;
    }
};

// Time Complexity: O(N!)
// Space Complexity: O(N^2) for the board and O(N) for the recursion stack.
// The O(N^2) space complexity is due to the board, which is an N x N grid. The O(N) space complexity for the recursion stack is because in the worst case, we can have N recursive calls on the stack at any given time.
// The O(N!) time complexity is because we are generating all possible permutations of N queens, and for each permutation, we are checking if it is valid. The number of valid permutations is bounded by N!, which is the factorial of N.