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
        vector<TreeNode*> res;
        if (start <= end) {
            for (int index = start; index <= end; ++index) {
                vector<TreeNode*> left = generateTreesCore(start, index-1);
                vector<TreeNode*> right = generateTreesCore(index+1, end);
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
        else res.push_back(nullptr);
        return res;
    }
};
