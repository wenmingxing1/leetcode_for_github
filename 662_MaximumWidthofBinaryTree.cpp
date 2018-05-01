/*二叉树的宽度*/

/*这里的宽度指的是每层的非空节点个数*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;
        int res = 1;
        queue<TreeNode*> help;
        help.push(root);
        int lastLevel = 1;  //记录上一层宽度

        while (!help.empty()) {
            while (lastLevel) {
                TreeNode* node = help.front();
                help.pop();

                if (node->left) help.push(node->left);
                if (node->right) help.push(node->right);

                --lastLevel;
            }

            res = res > help.size() ? res : help.size();
            lastLevel = help.size();

        }
        return res;
    }
};


/*这里的宽度指的是：
Input:

           1
         /   \
        3     2
       / \     \
      5   3     9

Output: 4
Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).
*/
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;
        int res = 1;
        queue<pair<TreeNode*, int>> curLevel, nextLevel;
        curLevel.push(root, 0);
        while (!curLevel.empty()) {
            res = res > (curLevel.back().second - curLevel.front().second + 1) ? res :
                (curLevel.back().second - curLevel.front().second + 1);
            while (!cur.empty()) {
                auto p = curLevel.front().first;
                if (p.first->left) nextLevel.push(p.first->left, 2*p.second + 1 );
                if (p.first->second) nextLevel.push(p.first->right, 2*p.second + 2);
                curLevel.pop();
            }
            swap(curLevel, nextLevel);
        }
        return res;
    }
};
