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
    //剑指offer18题的变形
    bool isSubtree(TreeNode* s, TreeNode* t) {
        bool res = false;
        //通过遍历找到与t头结点相同的结点
        if (s != NULL && t != NULL){
            if (s->val == t->val)
                res = DoesHas(s, t);    //找到之后进行判断
            if (!res)
                res = isSubtree(s->left, t);
            if (!res)
                res = isSubtree(s->right, t);
        }
        return res;
    }
private:
    bool DoesHas(TreeNode* s, TreeNode* t){
        if (s == NULL && t != NULL)
            return false;
        if (t == NULL && s != NULL)
            return false;
        if (s == NULL && t == NULL)
            return true;
        if (s->val != t->val)
            return false;

        return DoesHas(s->left, t->left) && DoesHas(s->right, t->right);
    }
};
