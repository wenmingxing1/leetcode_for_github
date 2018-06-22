#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x):val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr) return nullptr;
        ListNode* newHead = new ListNode(0);
        newHead->next = head;
        ListNode* slowPre = newHead;
        ListNode* slowNode = head;
        ListNode* fastPre = nullptr;
        ListNode* fastNode = head;
        ListNode* fastNext = nullptr;

        while (slowNode && (slowNode->val < x)) {
            slowNode = slowNode->next;
            slowPre = slowPre->next;
        }

        fastPre = slowNode;
        if (slowNode)
            fastNode = slowNode->next;
        else return head;

        while (fastNode) {
            if (fastNode->val < x) {
                fastNext = fastNode->next;
                fastPre->next = fastNext;

                slowPre->next = fastNode;
                fastNode->next = slowNode;

                slowPre = fastNode;
                fastNode = fastNext;
            }
            else {
                fastPre = fastNode;
                fastNode = fastNode->next;
            }
        }
        return newHead->next;
    }
};
