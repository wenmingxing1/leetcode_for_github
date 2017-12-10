/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//利用前序遍历，对于每个遍历到的节点进行处理，维护一个变量pre来记录之前路径之和
//然后cur为pre加上当前节点值，如果cur等于sum，那么返回结果时要加1，
//然后对当前节点的左右子节点调用递归函数求解
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if (root == NULL)
            return 0;
        return Sum(root, 0, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
private:
    //pre为前面节点的和，cur为前面加上现在遍历到的节点；
    int Sum(TreeNode* root, int pre, int sum){
        if (root == NULL)
            return 0;
        int cur = pre + root->val;

        return (cur == sum) + Sum(root->left, cur, sum) + Sum(root->right, cur, sum);
    }
};
