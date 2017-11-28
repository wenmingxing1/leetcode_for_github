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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL)
            return NULL;

        //第一个链表长度
        int lengthA = lengthList(headA);
        //第二个链表长度
        int lengthB = lengthList(headB);
        int diff = lengthA - lengthB;

        ListNode* Anode = headA;
        ListNode* Bnode = headB;

        if (diff > 0){  //A长，先让A移动diff
            for (int i = 0; i < diff; ++i){
                Anode = Anode->next;
            }
        }
        else if (diff < 0){
            for (int i = 0; i < -diff; ++i){
                Bnode = Bnode->next;
            }
        }

        while (Anode != Bnode){
            Anode = Anode->next;
            Bnode = Bnode->next;
        }
        return Anode;

    }
private:
    int lengthList(ListNode *head){
        if (head == NULL)
            return 0;
        int length = 1;
        ListNode* node = head;
        while (node->next != NULL){
            node = node->next;
            ++length;
        }
        return length;
    }
};
