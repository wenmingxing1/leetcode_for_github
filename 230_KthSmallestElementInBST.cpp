#include<iostream>

using namespace std;

struct treeNode {
    int val;
    treeNode* left;
    treeNode* right;

    treeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    treeNode* kthSmallest(treeNode* root, int k) {
        if (root == nullptr || k <= 0)    return nullptr;
        return kthSmallest(root, k);
    }

private:
    treeNode* kthSmallestCore(treeNode* root, int& k) {
        treeNode* res = nullptr;
        if (root->left) res = kthSmallestCore(root->left, k);

        if (res == nullptr) {
            if (k == 1)
                res = root;
            else
                --k;
        }

        if (res == nullptr && root->right)
            res = kthSmallestCore(root->right, k);

        return res;
    }
};
