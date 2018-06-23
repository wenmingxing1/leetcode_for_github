#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x):val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) return nullptr;

        int length = 0;
        ListNode* node = head;
        while (node) {
            ++length;
            node = node->next;
        }

        k = k % length;

        if (k == 0) return head;

        int length1= length - k;

        ListNode* head1 = head;
        ListNode* tail1 = head;
        ListNode* head2 = nullptr;

        while (length1-1) {
            tail1 = tail1->next;
            --length1;
        }

        head2 = tail1->next;

        tail1->next = nullptr;

        ListNode* node2 = head2;
        while (node2->next) {
            node2 = node2->next;
        }

        node2->next = head1;

        return head2;
    }
};
