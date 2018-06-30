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
    //剑指offer上原题，与83做比较，需要考虑head被删除的可能性
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* first = new ListNode(-1);     //赋值为-1，并不参与比较
        first->next = head;
        ListNode* pNode = head;
        ListNode* pre = first;  //在head前设一个节点

        while (pNode != NULL && pNode->next != NULL){
            if (pNode->val == pNode->next->val){
                //跳过相同结点
                int val = pNode->val;
                while (pNode != NULL && val == pNode->val){
                    pNode = pNode->next;
                }
                pre->next = pNode;
            }
            else{
                pre = pNode;
                pNode = pNode->next;
            }
        }
        return first->next;
    }
};
