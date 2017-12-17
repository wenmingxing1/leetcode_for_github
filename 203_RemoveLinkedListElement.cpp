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
        ListNode* NewHead = new ListNode(0);    //�½�ͷ��㣬���ڴ����һ���ڵ�ֵ��Ϊval�����
        NewHead->next = head;
        ListNode* pre = NewHead;
        ListNode* pNode = pre->next;
        while (pNode != NULL){
            //ִ��ɾ��
            if (pNode->val == val){
                pNode = pNode->next;
                pre->next = pNode;
            }
            //����pre��pNode
            else{
                pre = pNode;
                pNode = pNode->next;
            }
        }

        return NewHead->next;
    }
};
