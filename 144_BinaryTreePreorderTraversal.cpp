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
    //�ݹ�汾
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preorderTraversal(root, res);
        return res;
    }
private:
    void preorderTraversal(TreeNode* root, vector<int>& res){
        if (root == NULL)
            return;
        res.push_back(root->val);
        if (root->left) preorderTraversal(root->left, res);
        if (root->right) preorderTraversal(root->right, res);
    }
};

//�Ժ��Ϸǵݹ�汾
class Solution2
{

};
