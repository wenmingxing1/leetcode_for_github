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
    //��ָoffer���������⣬��ȫ���ظ�Ԫ�ض�ɾ������������Ҫ���ظ�Ԫ������һ�������Բ���Ҫ��headǰ����first
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode* pNode = head;
        ListNode* pre = pNode;
        while (pNode != NULL && pNode->next != NULL){
            if (pNode->val == pNode->next->val){
                int val = pNode->val;
                //�����ظ�Ԫ��
                while (pNode != NULL && val == pNode->val){
                    pNode = pNode->next;
                }
                pre->next = pNode;
                pre = pNode;
            }
            else{
                pNode = pNode->next;
                pre = pNode;
            }
        }
        return head;
    }
};
