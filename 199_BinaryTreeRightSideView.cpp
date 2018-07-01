#include<iostream>
#include<queue>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

//ʵ�ʿ���������Ĳ������
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return vector<int>();

        vector<int> res;
        queue<TreeNode*> levelOrder;
        levelOrder.push(root);
        int count = 1;  //��¼��һ�����

        while (!levelOrder.empty()) {
            res.push_back(levelOrder.back()->val);
            count = levelOrder.size();

            while (count) {
                TreeNode* node = levelOrder.front();
                levelOrder.pop();
                if (node->left) levelOrder.push(node->left);
                if (node->right) levelOrder.push(node->right);
                --count;
            }

        }
        return res;
    }
};
