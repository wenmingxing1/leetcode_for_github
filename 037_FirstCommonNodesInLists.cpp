#include<iostream>
#include<stack>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	//ListNode(int x) :
	//		val(x), next(NULL) {

};

/*==================利用快慢指针======================*/
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if (pHead1 == NULL || pHead2 == NULL)
            return NULL;
        int pHead1_size = 0;
        int pHead2_size = 0;

        ListNode* pNode1 = pHead1;
        ListNode* pNode2 = pHead2;
        while (pNode1 != NULL){		//得到pHead1的size
            pHead1_size++;
            pNode1 = pNode1->next;
        }
        while (pNode2 != NULL){		//得到pHead2的size
            pHead2_size++;
            pNode2 = pNode2->next;
        }

        int length = pHead1_size - pHead2_size;
        //cout << length << endl;
        if (length > 0){
            pNode2 = pHead2;
            pNode1 = pHead1;
            while (length != 0){
                pNode1 = pNode1->next;
                length--;
            }
        }
        else if (length < 0){
            pNode1 = pHead1;
            pNode2 = pHead2;
            while (length != 0){
                pNode2 = pNode2->next;
                length++;
            }
        }
        else if (length == 0){
            pNode1 = pHead1;
            pNode2 = pHead2;
        }

        while (pNode1->val != pNode2->val){
            pNode1 = pNode1->next;
            pNode2 = pNode2->next;
        }
        return pNode1;

    }
};

/*=================利用栈=======================*/
class Solution2
{
public:
    ListNode* Find(ListNode* pHead1, ListNode* pHead2)
    {
        stack<ListNode*> stack1;
        stack<ListNode*> stack2;
        for (ListNode* pNode1 = pHead1; pNode1 != NULL; pNode1 = pNode1->next){
            stack1.push(pNode1);
        }
        for (ListNode* pNode2 = pHead2; pNode2 != NULL; pNode2 = pNode2->next){
            stack2.push(pNode2);
        }

        while (stack1.top()->val == stack2.top()->val){
            stack1.pop();
            stack2.pop();
        }
        return stack1.top()->next;
    }
};

int main()
{
    ListNode List1[5];
    ListNode List2[6];
    ListNode* result;
    List1[0].val = 1;
    List1[0].next = &List1[1];
    List1[1].val = 2;
    List1[1].next = &List1[2];
    List1[2].val = 3;
    List1[2].next = &List1[3];
    List1[3].val = 6;
    List1[3].next = &List1[4];
    List1[4].val = 7;
    List1[4].next = NULL;

    List2[0].val = 8;
    List2[0].next = &List2[1];
    List2[1].val = 9;
    List2[1].next = &List2[2];
    List2[2].val = 4;
    List2[2].next = &List2[3];
    List2[3].val = 5;
    List2[3].next = &List2[4];
    List2[4].val = 6;
    List2[4].next = &List2[5];
    List2[5].val = 7;
    List2[5].next = NULL;

    Solution solu;
    Solution2 solu2;
    cout << solu2.Find(List1, List2)->val << endl;

    result = solu.FindFirstCommonNode(List1, List2);
    cout << result->val << endl;

    return 0;

}
