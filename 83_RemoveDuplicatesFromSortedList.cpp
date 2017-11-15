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
    //剑指offer上有类似题，将全部重复元素都删除，而此题需要在重复元素中流一个，所以不需要在head前设置first
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode* pNode = head;
        ListNode* pre = pNode;
        while (pNode != NULL && pNode->next != NULL){
            if (pNode->val == pNode->next->val){
                int val = pNode->val;
                //跳过重复元素
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
