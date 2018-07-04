#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == nullptr) return;
        if (root->left == nullptr && root->right == nullptr) return;

        TreeNode* Left = root->left;
        TreeNode* Right = root->right;

        flatten(Left);
        flatten(Right);

        root->right = Left;
        TreeNode* node = root;
        while (node->right) {
            node = node->right;
        }

        node->right = Right;
        root->left = nullptr;
    }
};
