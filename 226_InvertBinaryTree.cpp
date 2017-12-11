//½£Ö¸offer19Ìâ
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
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL || (root->left == NULL && root->right == NULL) )
            return root;

        swap(root->left, root->right);

        invertTree(root->left);
        invertTree(root->right);

        return root;

    }
};
