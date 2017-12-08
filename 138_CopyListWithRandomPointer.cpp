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
        //��ֳ����ԭʼ����ÿ���ڵ����ԭʼ�ڵ���棻
        copyList(head);
        //��randomָ�븴�ƹ�����
        copyRandom(head);
        //�������
        return segmentList(head);
    }
private:
    void copyList(RandomListNode* head){
        RandomListNode* pNode = head;
        while (pNode != NULL){
            RandomListNode* pNext = new RandomListNode(pNode->label);    //ֱ�ӹ��죬���Գ��Ժ�������
            //pNext->label = pNode->label;
            pNext->next = pNode->next;
            pNode->next = pNext;
            pNext->random = NULL;   //�Ƚ�random��Ϊ��

            pNode = pNext->next;
        }
    }

    void copyRandom(RandomListNode* head){
        RandomListNode* pNode = head;
        while (pNode != NULL){
            RandomListNode* pNext = pNode->next;
            if (pNode->random != NULL)      //һ��Ҫ����һ���ж�
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
