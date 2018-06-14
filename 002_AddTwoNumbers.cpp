#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* node1 = l1;
        ListNode* node2 = l2;
        ListNode* newHead = new ListNode(0);
        ListNode* pre = newHead;

        while (node1 || node2) {
            int node1Int = (node1==nullptr) ? 0 : node1->val;
            int node2Int = (node2==nullptr) ? 0 : node2->val;

            int sum = node1Int + node2Int + carry;
            carry = sum / 10;
            sum = sum % 10;

            ListNode* newNode = new ListNode(sum);
            pre->next = newNode;
            pre = pre->next;

            if (node1)
                node1 = node1->next;
            if (node2)
                node2 = node2->next;

        }
        if (carry != 0) {
            ListNode* node = new ListNode(carry);
            pre->next = node;
        }
        return newHead->next;
    }
};


