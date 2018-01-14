//剑指offer第6题变型
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty() && postorder.empty())
            return nullptr;
        int length = inorder.size();
        int value = postorder[length-1];
        TreeNode* root = new TreeNode(value);

        //找到中序中的root位置
        int indexRoot = 0;
        for (int i = 0; i < length; ++i) {
            if (inorder[i] == value) {
                indexRoot = i;
                break;
            }
        }

        vector<int> inLeft, inRight, postLeft, postRight;
        for (int i = 0; i < indexRoot; ++i) {
            inLeft.push_back(inorder[i]);
            postLeft.push_back(postorder[i]);
        }

        for (int i = indexRoot; i < length-1; ++i) {
            inRight.push_back(inorder[i+1]);
            postRight.push_back(postorder[i]);
        }

        root->left = buildTree(inLeft, postLeft);
        root->right = buildTree(inRight, postRight);

        return root;

    }
};
