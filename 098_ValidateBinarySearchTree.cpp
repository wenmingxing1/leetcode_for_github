#include<iostream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MAX, LONG_MIN);    //使用LONG是为了包含INT_MAX与INT_MIN
    }
private:
    bool isValidBST(TreeNode* root, long Max, long Min) {
        if (root == nullptr) return true;
        if (root->val <= Min || root->val >= Max) return false;
        return isValidBST(root->left, root->val, Min)
            && isValidBST(root->right, Max, root->val);
    }

};
