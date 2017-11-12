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
    //剑指offer上的题，用队列完成二叉树的层序遍历
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL)
            return res;
        std::queue<TreeNode*> nodes;
        nodes.push(root);
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
            res.push_back(temp);
        }
        return res;
    }
};
