/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    bool ans = false;
    bool match(TreeNode *first, TreeNode *second)
    {
        if (first != NULL && second != NULL)
        {
            bool a = match(first->left, second->left);
            bool b = match(first->right, second->right);
            if ((first->val == second->val) && a && b)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else if (first == NULL && second == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void flip(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
        flip(root->left);
        flip(root->right);
    }
    bool isSymmetric(TreeNode *root)
    {
        flip(root->left);
        if (root->left == NULL && root->right != NULL)
        {
            return false;
        }
        else if (root->left != NULL && root->right == NULL)
        {
            return false;
        }
        else if (root->left == NULL && root->right == NULL)
        {
            return true;
        }
        bool x = match(root->left, root->right);
        if (x)
        {
            ans = true;
        }
        return ans;
    }
};