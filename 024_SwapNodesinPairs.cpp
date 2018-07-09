#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr) return nullptr;

        ListNode* node = head;
        ListNode* next = nullptr;
        ListNode* newhead = new ListNode(0);
        newhead->next = head;
        ListNode* pre = newhead;


        while (node && node->next) {
            next = node->next;

            if (next) {
                pre->next = next;
                node->next = next->next;
                next->next = node;

                pre = node;
                node = node->next;
            }
        }
        return newhead->next;
    }
};
