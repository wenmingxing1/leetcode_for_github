#include<iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr || q == nullptr) return false;

        //根据后序遍历规则，必须先要完成对左右子树的判断
        if (isSameTree(p->left, q->left)&&isSameTree(p->right,q->right)&&(p->val==q->val)) return true;
        else return false;
    }
};

//其实是相同的,只是把值的判断放到了不同的地方
class Solution2 {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr || q == nullptr) return false;
        if (p->val != q->val) return false;

        return isSameTree(p->left, q->left)&&isSameTree(p->right,q->right);
    }
};
