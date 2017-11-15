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
    //��ָofferԭ�⣬Ѱ���л���������ʼ�ڵ�
    ListNode *detectCycle(ListNode *head) {
        ListNode* res = NULL;
        ListNode* node = Cycle(head);
        int count = Count(head);

        if (count != 0){
            ListNode* slow = head;
            ListNode* quick = head;
            for (int i = 0; i < count; ++i){
                quick = quick->next;
            }

            while(slow != quick){
                slow = slow->next;
                quick = quick->next;
            }
            res = slow;
        }
        return res;
    }
private:
    //�ж������Ƿ��л������ػ��е�һ���ڵ�
    ListNode* Cycle(ListNode* head){
        ListNode* node = NULL;
        if (head != NULL && head->next != NULL){
            ListNode* slow = head;
            ListNode* quick = head->next;
            while (slow->next != NULL && quick->next != NULL && quick->next->next != NULL){
                if (slow == quick){
                    node = slow;
                    break;
                }
                else{
                    slow = slow->next;
                    quick = quick->next->next;
                }
            }
        }
        return node;
    }
    //����Ԫ�صĸ���
    int Count(ListNode* head){
        int count = 0;
        ListNode* node = Cycle(head);
        if (node != NULL){
            ListNode* pNode = node;
            count += 1;
            while (node->next != pNode){
                count++;
                node = node->next;
            }
        }
        return count;
    }

    //
};
