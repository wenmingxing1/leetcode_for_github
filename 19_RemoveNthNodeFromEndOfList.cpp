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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //�ҵ�������n���ڵ�,��������ָ�룬��һ������n��
        ListNode* pQuick = head;
        int step = n;
        while (step > 0){
            if (pQuick->next != NULL){
                pQuick = pQuick->next;
                --step;
            }
            else return head->next;   //֤��step���������ȣ������������ɾ��head���򷵻�head->next����
        }

        //��ʼͬʱ�ƶ�����ָ�룬��quickָ�뵽������β�˽ڵ��ʱ��slowָ�뵽�ﵹ����n+1���ڵ�
        ListNode* pSlow = head;
        while (pQuick->next != NULL){
            pQuick = pQuick->next;
            pSlow = pSlow->next;
        }

        //ִ��ɾ��slow�Ĳ���
        pSlow->next = pSlow->next->next;

        return head;
    }
};
