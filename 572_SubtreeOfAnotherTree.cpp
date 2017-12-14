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
    //��ָoffer18��ı���
    bool isSubtree(TreeNode* s, TreeNode* t) {
        bool res = false;
        //ͨ�������ҵ���tͷ�����ͬ�Ľ��
        if (s != NULL && t != NULL){
            if (s->val == t->val)
                res = DoesHas(s, t);    //�ҵ�֮������ж�
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
