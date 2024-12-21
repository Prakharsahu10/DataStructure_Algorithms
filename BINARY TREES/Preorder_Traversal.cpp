/* Preorder Traversal in Binary Tree*/
/* Root -> Left -> Right */

class Solution
{
public:
    vector<int> arr;
    vector<int> preorderTraversal(TreeNode *root)
    {
        if (root)
        {
            arr.push_back(root->val);
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }
        return arr;
    }
};