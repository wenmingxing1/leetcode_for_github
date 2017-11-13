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

//�Ժ��Ϸǵݹ�汾
class Solution2
{

};
