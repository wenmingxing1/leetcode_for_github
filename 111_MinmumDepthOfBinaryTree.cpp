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
    //��ָoffer39������·����ģ�����Ϊ��·����̵ġ���᲻֮ͬ��������Ҫ�ж��Ƿ�������������
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
