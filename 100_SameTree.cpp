#include<iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr || q == nullptr) return false;

        //���ݺ���������򣬱�����Ҫ��ɶ������������ж�
        if (isSameTree(p->left, q->left)&&isSameTree(p->right,q->right)&&(p->val==q->val)) return true;
        else return false;
    }
};

//��ʵ����ͬ��,ֻ�ǰ�ֵ���жϷŵ��˲�ͬ�ĵط�
class Solution2 {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr || q == nullptr) return false;
        if (p->val != q->val) return false;

        return isSameTree(p->left, q->left)&&isSameTree(p->right,q->right);
    }
};
