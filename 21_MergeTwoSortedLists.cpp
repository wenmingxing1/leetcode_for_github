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
    //剑指offer17题：合并两个排序链表，采用递归的方式
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
