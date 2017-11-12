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
    //��ָofferԭ�⣬�����������־λ�ж��Ƿ���Ҫ��ת
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL)
            return res;
        std::queue<TreeNode*> nodes;
        nodes.push(root);
        bool even = true;   //��־λ���ж��Ƿ���Ҫ��ת,ż���㲻��Ҫ��ת
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
            if (!even)  //���Ϊ�����㣬��תtemp
                reverse(temp.begin(), temp.end());
            even = !even;     //�ı��־λ
            res.push_back(temp);
        }
        return res;
    }
};
