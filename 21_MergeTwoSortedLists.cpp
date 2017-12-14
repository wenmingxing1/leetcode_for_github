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
    //��ָoffer17�⣺�ϲ����������������õݹ�ķ�ʽ
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        ListNode *mergeHead = NULL;
        if (l1->val < l2->val){
            mergeHead = l1;
            mergeHead->next = mergeTwoLists(l1->next, l2);
        }
        else {
            mergeHead = l2;
            mergeHead->next = mergeTwoLists(l1, l2->next);
        }

        return mergeHead;
    }
};
