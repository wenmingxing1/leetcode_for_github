#include<iostream>
#include<queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullprt) {}
};

//实际考察的是中序遍历，这里用的是递归方式
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        BSTinorder(root);
    }

    bool hasNext() {
        return !inorder.empty();
    }

    int next() {
        int res = inorder.front()->val;
        inorder.pop();
        return res;
    }
private:
    queue<TreeNode*> inorder;
    void BSTinorder(TreeNode* root) {
        if (root == nullptr) return;
        if (root->left) BSTinorder(root->left);
        inorder.push(root);
        if (root->right) BSTinorder(root->right);
    }
};

