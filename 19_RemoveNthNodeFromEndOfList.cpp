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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //找到倒数第n个节点,设置两个指针，第一个先走n步
        ListNode* pQuick = head;
        int step = n;
        while (step > 0){
            if (pQuick->next != NULL){
                pQuick = pQuick->next;
                --step;
            }
            else return head->next;   //证明step等于链表长度，则这种情况下删除head，则返回head->next即可
        }

        //开始同时移动两个指针，当quick指针到达链表尾端节点的时候，slow指针到达倒数第n+1个节点
        ListNode* pSlow = head;
        while (pQuick->next != NULL){
            pQuick = pQuick->next;
            pSlow = pSlow->next;
        }

        //执行删除slow的操作
        pSlow->next = pSlow->next->next;

        return head;
    }
};
