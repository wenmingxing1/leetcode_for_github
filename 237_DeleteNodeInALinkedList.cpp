/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//��ָoffer13�⣬��O(1)�ĸ��Ӷ�ɾ������ڵ�ı���
class Solution {
public:
    void deleteNode(ListNode* node) {
        if (node->next != NULL){    //����������ʵ����������ᷢ��
            node->val = node->next->val;
            node->next = node->next->next;
        }
    }
};
