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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL)
            return NULL;
        ListNode* NewHead = new ListNode(0);    //新建头结点，便于处理第一个节点值就为val的情况
        NewHead->next = head;
        ListNode* pre = NewHead;
        ListNode* pNode = pre->next;
        while (pNode != NULL){
            //执行删除
            if (pNode->val == val){
                pNode = pNode->next;
                pre->next = pNode;
            }
            //更新pre和pNode
            else{
                pre = pNode;
                pNode = pNode->next;
            }
        }

        return NewHead->next;
    }
};
