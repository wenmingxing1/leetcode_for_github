/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == NULL)
            return NULL;

        ListNode* newHead = new ListNode(0);    //����Ҫnewһ�����������ݽṹ
        newHead->next = head;
        ListNode* pre = newHead;
        for (int i = 0; i < m-1; ++i){
            pre = pre->next;
        }
        //��ʱpreΪ��m���ڵ��ǰһ���ڵ�

        ListNode* pNode = pre->next;

        //���Ͻ���һ�ڵ���뵽pre��pre->next֮��
        for (int i = 0; i < n-m; ++i){
            ListNode* pNext = pNode->next;
            pNode->next = pNext->next;
            pNext->next = pre->next;
            pre->next = pNext;
        }

        return newHead->next;
    }
};
