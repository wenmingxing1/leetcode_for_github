/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//剑指offer39_2题，判断是否是AVL树
class Solution {
public:
    //利用二叉树的深度解法，有可能一个节点需要遍历多次
    bool isBalanced(TreeNode* root) {
        if (root == NULL)
            return true;
        int left = Depth(root->left);
        int right = Depth(root->right);

        int diff = left - right;
        if (diff > 1 || diff < -1)
            return false;
        else
            return (isBalanced(root->left) && isBalanced(root->right));
    }

    int Depth(TreeNode* root){
        if (root == NULL)
            return 0;
        int left = Depth(root->left);
        int right = Depth(root->right);

        return 1+(left>right?left:right);
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution_optimal {
public:
    //每个节点只需遍历一次的做法，判断左右子树是否平衡，然后更新根结点深度，实质上是后序遍历思想
    bool isBalanced(TreeNode* root) {
        int Depth = 0;
        return isBalancedCore(root, &Depth);
    }
private:
    bool isBalancedCore(TreeNode* root, int* Depth){
        if (root == NULL){  //递归结束条件
            *Depth = 0;
            return true;
        }

        int left, right;
        //判断左右子树是否balance
        if (isBalancedCore(root->left, &left) && isBalancedCore(root->right, &right)){
            int diff = left - right;
            if (diff <= 1 && diff >= -1){
                *Depth = 1+(left>right?left:right);     //更新根结点深度
                return true;
            }
        }
        return false;
    }
};
