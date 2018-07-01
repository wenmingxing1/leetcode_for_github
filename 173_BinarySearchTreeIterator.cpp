#include<iostream>
#include<queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullprt) {}
};

//ʵ�ʿ��������������������õ��ǵݹ鷽ʽ
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

