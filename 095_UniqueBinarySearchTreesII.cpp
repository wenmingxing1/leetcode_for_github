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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return vector<TreeNode*>();
        vector<TreeNode*> res = generateTreesCore(1, n);
        return res;
    }
private:
    vector<TreeNode*> generateTreesCore(int start, int end) {
        if (start < end) {
            vector<TreeNode*> res;
            for (int index = start; i <= end; ++i) {
                vector<TreeNode*> left = generateTreeCore(start, index-1);
                vector<TreeNode*> right = generateTreeCore(index+1, end);
                for (auto l : left) {
                    for (auto r : right) {
                        TreeNode* root = new TreeNode(index);
                        root->left = l;
                        root->right = r;
                        res.push_back(root);
                    }
                }
            }
        }
        return res;
    }
};
