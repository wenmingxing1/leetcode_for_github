/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//剑指offer13题，在O(1)的复杂度删除链表节点的变形
class Solution {
public:
    void deleteNode(ListNode* node) {
        if (node->next != NULL){    //按照题意其实这种情况不会发生
            node->val = node->next->val;
            node->next = node->next->next;
        }
    }
};
