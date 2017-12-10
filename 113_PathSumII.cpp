/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//剑指offer25题：二叉树中和为某一值的路径
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        if (root == NULL)
            return res;

        vector<int> path;
        FindPath(root, sum, 0, path, res);

        return res;
    }
private:
    void FindPath(TreeNode* root, int sum, int curSum, vector<int> path, vector<vector<int>>& res){
        path.push_back(root->val);
        curSum += root->val;

        if (curSum == sum && isLeaf(root)){
            res.push_back(path);
        }

        if (root->left) FindPath(root->left, sum, curSum, path, res);
        if (root->right) FindPath(root->right, sum, curSum, path, res);

        path.pop_back();    //返回父结点之前，需要删除当前结点
    }

    //判断是否到达叶子节点
    bool isLeaf(TreeNode* node){
        if (node->left == NULL && node->right == NULL)
            return true;
        return false;
    }
};
