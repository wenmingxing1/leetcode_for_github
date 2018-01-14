//��ָoffer��6��
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int length = preorder.size();
        if (preorder.empty() || inorder.empty())
            return nullptr;
        int value = preorder[0];
        TreeNode* root = new TreeNode(value);

        //�ҵ������и�����λ��
        int indexRoot;
        for (int i = 0; i < length; ++i) {
            if (inorder[i] == value)
            {
                indexRoot = i;
                break;
            }

        }

        //���Էֿ���������
        vector<int> preLeft;
        vector<int> preRight;
        vector<int> inLeft;
        vector<int> inRight;

        for (int i = 0; i < indexRoot; ++i) {
            preLeft.push_back(preorder[i+1]);
            inLeft.push_back(inorder[i]);
        }

        for (int i = indexRoot+1; i < length; ++i) {
            preRight.push_back(preorder[i]);
            inRight.push_back(inorder[i]);
        }

        root->left = buildTree(preLeft, inLeft);
        root->right = buildTree(preRight, inRight);

        return root;

    }
};
