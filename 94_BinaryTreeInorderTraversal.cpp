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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorderTraversal(root, res);
        return res;
    }
private:
    void inorderTraversal(TreeNode* root, vector<int>& res){
        if (root == NULL)
            return;
        if (root->left)
            inorderTraversal(root->left, res);
        res.push_back(root->val);
        if (root->right)
            inorderTraversal(root->right, res);
    }
};

//�Ժ��Ϸǵݹ�汾
class Solution2
{

};
