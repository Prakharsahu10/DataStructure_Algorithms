/*

Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and the rat cannot move to it while value 1 at a cell in the matrix represents that rat can travel through it.

Note: In a path, no cell can be visited more than one time.

Print the answer in lexicographical(sorted) order

Examples:

Example 1:

Input:
N = 4
m[][] = {{1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}}

Output: DDRDRR DRDDRR

Explanation:



The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR and DDRDRR, when printed in sorted order we get DDRDRR DRDDRR.

Example 2:

Input: N = 2
       m[][] = {{1, 0},
                {1, 0}}

Output:
 No path exists and the destination cell is blocked.

*/

#include <iostream>
#include <vector>
using namespace std;

void helper(vector<vector<int>> &mat, int r, int c, string path, vector<string> &ans)
{

    int n = mat.size();
    if (r < 0 || c < 0 || r >= n || c >= n || mat[r][c] == 0 || mat[r][c] == true)
    {
        return;
    }

    if (r == n - 1 && c == n - 1)
    {
        ans.push_back(path);
        return;
    }

    mat[r][c] = -1; // Mark the cell as visited
    // Move in all 4 directions

    helper(mat, r + 1, c, path + 'D', ans); // Down
    helper(mat, r, c + 1, path + 'R', ans); // Right
    helper(mat, r - 1, c, path + 'U', ans); // Up
    helper(mat, r, c - 1, path + 'L', ans); // Left

    mat[r][c] = -1; // Backtrack and unmark the cell
}

vector<string> findPath(vector<vector<int>> &mat)
{
    int n = mat.size();
    vector<string> ans;
    string path = "";

    helper(mat, 0, 0, path, ans);

    return ans;
}

int main()
{
    vector<vector<int>> mat = {{1, 0, 0, 0},
                               {1, 1, 0, 1},
                               {1, 1, 0, 0},
                               {0, 1, 1, 1}};
    vector<string> paths = findPath(mat);
    for (string path : ans)
    {
        cout << path << " ";
    }

    return 0;
}