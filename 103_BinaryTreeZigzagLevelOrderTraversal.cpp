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
    //剑指offer原题，层序遍历，标志位判断是否需要翻转
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL)
            return res;
        std::queue<TreeNode*> nodes;
        nodes.push(root);
        bool even = true;   //标志位，判断是否需要翻转,偶数层不需要翻转
        while (!nodes.empty()){
            vector<int> temp;
            int size = nodes.size();
            for (int i = 0; i < size; ++i){
                TreeNode* pNode = nodes.front();
                temp.push_back(pNode->val);
                nodes.pop();

                if (pNode->left)
                    nodes.push(pNode->left);
                if (pNode->right)
                    nodes.push(pNode->right);

            }
            if (!even)  //如果为奇数层，则翻转temp
                reverse(temp.begin(), temp.end());
            even = !even;     //改变标志位
            res.push_back(temp);
        }
        return res;
    }
};
