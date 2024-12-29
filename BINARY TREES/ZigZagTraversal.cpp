/* Zig-Zag Traversal of a Binary Tree */
/*

Problem Statement: Given a Binary Tree, print the zigzag traversal of the Binary Tree. Zigzag traversal of a binary tree is a way of visiting the nodes of the tree in a zigzag pattern, alternating between left-to-right and right-to-left at each level.

Examples
Example 1:
Input:Binary Tree: 1 2 3 4 5 -1 6


Output: [[1],[3, 2],[4, 5, 6]]
Explanation:
Level 1 (Root): Visit the root node 1 from left to right. Zigzag Traversal: [1]
Level 2: Visit nodes at this level in a right-to-left order. Zigzag Traversal:  [1], [3, 2]
Level 3: Visit nodes at this level in a left-to-right order. Zigzag Traversal:  [1], [3, 2], [4, 5, 6]

*/

#include <iostream>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

// Node structure for the binary tree
struct Node
{
    int data;
    Node *left;
    Node *right;
    // Constructor to initialize
    // the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    // Function to perform zigzag level
    // order traversal of a binary tree
    vector<vector<int>> ZigZagLevelOrder(Node *root)
    {
        // Vector to store the
        // result of zigzag traversal
        vector<vector<int>> result;

        // Check if the root is NULL,
        // return an empty result
        if (root == NULL)
        {
            return result;
        }

        // Queue to perform
        // level order traversal
        queue<Node *> nodesQueue;
        nodesQueue.push(root);

        // Flag to determine the direction of
        // traversal (left to right or right to left)
        bool leftToRight = true;

        // Continue traversal until
        // the queue is empty
        while (!nodesQueue.empty())
        {
            // Get the number of nodes
            // at the current level
            int size = nodesQueue.size();

            // Vector to store the values
            // of nodes at the current level
            vector<int> row(size);

            // Traverse nodes at
            // the current level
            for (int i = 0; i < size; i++)
            {
                // Get the front node
                // from the queue
                Node *node = nodesQueue.front();
                nodesQueue.pop();

                // Determine the index to insert the node's
                // value based on the traversal direction
                int index = leftToRight ? i : (size - 1 - i);

                // Insert the node's value at
                // the determined index
                row[index] = node->data;

                // Enqueue the left and right
                // children if they exist
                if (node->left)
                {
                    nodesQueue.push(node->left);
                }
                if (node->right)
                {
                    nodesQueue.push(node->right);
                }
            }

            // Switch the traversal
            // direction for the next level
            leftToRight = !leftToRight;

            // Add the current level's
            // values to the result vector
            result.push_back(row);
        }

        // Return the final result of
        // zigzag level order traversal
        return result;
    }
};

// Helper function to print the result
void printResult(const vector<vector<int>> &result)
{
    for (const auto &row : result)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main()
{
    // Creating a sample binary tree
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution solution;

    // Get the zigzag level order traversal
    vector<vector<int>> result = solution.ZigZagLevelOrder(root);

    // Print the result
    printResult(result);

    return 0;
}
