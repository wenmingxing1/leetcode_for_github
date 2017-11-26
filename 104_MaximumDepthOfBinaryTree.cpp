/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    //剑指offer39题，求二叉树的深度
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        int left=0, right=0;
        if (root->left) left = maxDepth(root->left);
        if (root->right) right = maxDepth(root->right);
        return 1+(left>right?left:right);
    }
};
