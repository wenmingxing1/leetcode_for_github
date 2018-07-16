#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr) return nullptr;

        ListNode* newhead = new ListNode(0);

        ListNode* pre = newhead;

        ListNode* node = head;
        ListNode* next = nullptr;
        while (node) {
            next = node->next;
            //找到比node大的
            while (pre->next && pre->next->val <= node->val) {
                pre = pre->next;
            }

            node->next = pre->next;
            pre->next = node;
            node = next;

            pre = newhead;
        }

        return newhead->next;
    }
};
