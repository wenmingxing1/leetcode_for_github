/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//剑指offer25题：二叉树中和为某一值的路径的简化版
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        bool result = false;

        if (root == NULL)
            return false;

        //根据前序遍历找到叶子节点，如果和等于sum这直接返回true
        if (root->val == sum && root->left == NULL && root->right == NULL)
            return true;

        if (root->left) result = hasPathSum(root->left, sum - root->val);
        if (root->right && result == false) result = hasPathSum(root->right, sum - root->val);

        return result;
    }
};
