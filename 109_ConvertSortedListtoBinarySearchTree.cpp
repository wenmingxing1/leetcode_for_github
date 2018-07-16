#include<iostream>
#inlcude<vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr) return nullptr;
        if (head->next == nullptr) {
            TreeNode* temp = new TreeNode(head->val);
            return temp;
        }

        //找到根结点
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* preslow = new ListNode(0);
        preslow->next = slow;

        while (fast && fast->next) {
            fast = fast->next;
            if (fast)
                fast = fast->next;

            preslow = preslow->next;
            slow = slow->next;
        }

        TreeNode* root = new TreeNode(slow->val);

        preslow->next = nullptr;

        TreeNode* left = sortedListToBST(head);
        TreeNode* right = sortedListToBST(slow->next);

        root->left = left;
        root->right = right;

        return root;
    }
};
