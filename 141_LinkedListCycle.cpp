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
    //快慢指针判断链表是否有环
    bool hasCycle(ListNode *head) {
        bool res = false;
        if (head != NULL && head->next != NULL){
            ListNode* slow = head;
            ListNode* quick = head->next;
            while (slow->next != NULL && quick->next != NULL && quick->next->next != NULL){
                if (slow->val == quick->val){
                    res = true;
                    break;
                }
                else{
                    slow = slow->next;
                    quick = quick->next->next;
                }
            }
        }
        return res;
    }
};
