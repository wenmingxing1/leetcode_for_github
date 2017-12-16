/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//��ָoffer16�⣺��ת����
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL)
            return NULL;
        ListNode* pre = NULL;
        ListNode* pNode = head;
        ListNode* pNext = NULL;
        while (pNode != NULL){
            pNext = pNode->next;    //Ϊ��ֹ������ѣ���Ҫ��¼next
            pNode->next = pre;
            pre = pNode;
            pNode = pNext;
        }
        return pre;
    }
};
