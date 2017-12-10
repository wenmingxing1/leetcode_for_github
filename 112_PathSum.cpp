/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//��ָoffer25�⣺�������к�Ϊĳһֵ��·���ļ򻯰�
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        bool result = false;

        if (root == NULL)
            return false;

        //����ǰ������ҵ�Ҷ�ӽڵ㣬����͵���sum��ֱ�ӷ���true
        if (root->val == sum && root->left == NULL && root->right == NULL)
            return true;

        if (root->left) result = hasPathSum(root->left, sum - root->val);
        if (root->right && result == false) result = hasPathSum(root->right, sum - root->val);

        return result;
    }
};
