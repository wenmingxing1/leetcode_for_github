/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//����ǰ�����������ÿ���������Ľڵ���д���ά��һ������pre����¼֮ǰ·��֮��
//Ȼ��curΪpre���ϵ�ǰ�ڵ�ֵ�����cur����sum����ô���ؽ��ʱҪ��1��
//Ȼ��Ե�ǰ�ڵ�������ӽڵ���õݹ麯�����
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if (root == NULL)
            return 0;
        return Sum(root, 0, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
private:
    //preΪǰ��ڵ�ĺͣ�curΪǰ��������ڱ������Ľڵ㣻
    int Sum(TreeNode* root, int pre, int sum){
        if (root == NULL)
            return 0;
        int cur = pre + root->val;

        return (cur == sum) + Sum(root->left, cur, sum) + Sum(root->right, cur, sum);
    }
};
