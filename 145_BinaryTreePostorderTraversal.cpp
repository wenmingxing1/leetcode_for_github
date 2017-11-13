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
    //递归版本
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorderTraversal(root, res);
        return res;
    }
private:
    void postorderTraversal(TreeNode* root, vector<int>& res){
        if (root == NULL)
            return;
        if (root->left) postorderTraversal(root->left, res);
        if (root->right) postorderTraversal(root->right, res);
        res.push_back(root->val);
    }
};

//以后补上非递归版本
class Solution2
{

};
