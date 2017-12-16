/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//剑指offer16题：翻转链表
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL)
            return NULL;
        ListNode* pre = NULL;
        ListNode* pNode = head;
        ListNode* pNext = NULL;
        while (pNode != NULL){
            pNext = pNode->next;    //为防止链表断裂，需要记录next
            pNode->next = pre;
            pre = pNode;
            pNode = pNext;
        }
        return pre;
    }
};
