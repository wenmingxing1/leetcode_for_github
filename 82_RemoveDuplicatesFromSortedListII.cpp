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
    //��ָoffer��ԭ�⣬��83���Ƚϣ���Ҫ����head��ɾ���Ŀ�����
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* first = new ListNode(-1);     //��ֵΪ-1����������Ƚ�
        first->next = head;
        ListNode* pNode = head;
        ListNode* pre = first;  //��headǰ��һ���ڵ�

        while (pNode != NULL && pNode->next != NULL){
            if (pNode->val == pNode->next->val){
                //������ͬ���
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
