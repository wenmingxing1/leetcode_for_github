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

        ListNode* newHead = new ListNode(0);    //必须要new一个完整的数据结构
        newHead->next = head;
        ListNode* pre = newHead;
        for (int i = 0; i < m-1; ++i){
            pre = pre->next;
        }
        //此时pre为第m个节点的前一个节点

        ListNode* pNode = pre->next;

        //不断将下一节点插入到pre与pre->next之间
        for (int i = 0; i < n-m; ++i){
            ListNode* pNext = pNode->next;
            pNode->next = pNext->next;
            pNext->next = pre->next;
            pre->next = pNext;
        }

        return newHead->next;
    }
};
