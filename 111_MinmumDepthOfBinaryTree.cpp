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
    //剑指offer39题是求路径最长的，此题为求路径最短的。体会不同之处在于需要判断是否有左右子树。
    int minDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        if (root->left == NULL)
            return 1+minDepth(root->right);
        if (root->right == NULL)
            return 1+minDepth(root->left);

        int left = 0;
        int right = 0;
        if (root->left)     left = minDepth(root->left);
        if (root->right)    right = minDepth(root->right);

        return 1+ (left<right?left:right);
    }
};
