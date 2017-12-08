/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        //增殖复制原始链表，每个节点放在原始节点后面；
        copyList(head);
        //将random指针复制过来；
        copyRandom(head);
        //拆分链表；
        return segmentList(head);
    }
private:
    void copyList(RandomListNode* head){
        RandomListNode* pNode = head;
        while (pNode != NULL){
            RandomListNode* pNext = new RandomListNode(pNode->label);    //直接构造，可以尝试后来构造
            //pNext->label = pNode->label;
            pNext->next = pNode->next;
            pNode->next = pNext;
            pNext->random = NULL;   //先将random设为空

            pNode = pNext->next;
        }
    }

    void copyRandom(RandomListNode* head){
        RandomListNode* pNode = head;
        while (pNode != NULL){
            RandomListNode* pNext = pNode->next;
            if (pNode->random != NULL)      //一定要有这一句判断
                pNext->random = pNode->random->next;

            pNode = pNext->next;
        }
    }

    RandomListNode* segmentList(RandomListNode* head){
        RandomListNode* pCopyHead = NULL;
        RandomListNode* pCopyNode = NULL;
        RandomListNode* pNode = head;

        if (pNode != NULL){
            pCopyHead = pCopyNode = pNode->next;
            pNode->next = pCopyNode->next;
            pNode = pNode->next;
        }

        while (pNode != NULL){
            pCopyNode->next = pNode->next;
            pCopyNode = pCopyNode->next;
            pNode->next = pCopyNode->next;
            pNode = pNode->next;
        }
        return pCopyHead;
    }

};
