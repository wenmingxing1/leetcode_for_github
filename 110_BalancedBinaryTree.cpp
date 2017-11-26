/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//��ָoffer39_2�⣬�ж��Ƿ���AVL��
class Solution {
public:
    //���ö���������Ƚⷨ���п���һ���ڵ���Ҫ�������
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
    //ÿ���ڵ�ֻ�����һ�ε��������ж����������Ƿ�ƽ�⣬Ȼ����¸������ȣ�ʵ�����Ǻ������˼��
    bool isBalanced(TreeNode* root) {
        int Depth = 0;
        return isBalancedCore(root, &Depth);
    }
private:
    bool isBalancedCore(TreeNode* root, int* Depth){
        if (root == NULL){  //�ݹ��������
            *Depth = 0;
            return true;
        }

        int left, right;
        //�ж����������Ƿ�balance
        if (isBalancedCore(root->left, &left) && isBalancedCore(root->right, &right)){
            int diff = left - right;
            if (diff <= 1 && diff >= -1){
                *Depth = 1+(left>right?left:right);     //���¸�������
                return true;
            }
        }
        return false;
    }
};
