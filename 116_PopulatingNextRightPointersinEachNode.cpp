#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x):val(x), left(nullptr), right(nullptr), next(nullptr) {}
};

// π”√≤„–Ú±È¿˙
class Solution {
public:
    void connect(TreeLinkNode* root) {
        if (root == nullptr) return nullptr;
        queue<TreeLinkNode*> help;
        help.push(root);

        int count = 1;

        while (!help.empty()) {
            count = help.size();

            while (count) {
                TreeLinkNode* node = help.front();
                help.pop();
                --count;

                if (count == 0) node->next = nullptr;
                else node->next = help.front();

                if (node->left) help.push(node->left);
                if (node->right) help.push(node->right);

            }
        }
    }
};
