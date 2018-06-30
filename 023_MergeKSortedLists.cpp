/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//利用mergeTwoLists函数的方法
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* mergeHead = NULL;
        int num = lists.size();
        if (num == 0)
            return NULL;
        if (num == 1)
            return lists[0];

        while (lists.size() > 1){
            mergeHead = mergeTwoLists(lists[lists.size()-2], lists[lists.size()-1]);
            lists.pop_back();
            lists.pop_back();
            lists.push_back(mergeHead);
        }
        return mergeHead;

    }
private:
    //合并两个链表
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;

        ListNode* mergeHead = NULL;

        if (list1->val < list2->val){
            mergeHead = list1;
            mergeHead->next = mergeTwoLists(list1->next, list2);
        }
        else {
            mergeHead = list2;
            mergeHead->next = mergeTwoLists(list1, list2->next);
        }

        return mergeHead;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//利用最小堆,不知道为什么有的测试样例不能通过
static bool HeapCompare(ListNode* list1, ListNode* list2){
    return list1->val > list2->val;
}
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> vec;
        int num = lists.size();
        for (int i = 0; i < num; ++i){
            ListNode* pNode = lists[i];
            while (pNode != NULL){
                vec.push_back(pNode);
                pNode = pNode->next;
            }
        }

        ListNode* mergeHead = NULL;
        make_heap(vec.begin(), vec.end(), HeapCompare);
        if (!vec.empty()){
            mergeHead = vec[0];
            pop_heap(vec.begin(), vec.end(), HeapCompare);
            vec.pop_back();
        }
        ListNode* curNode = mergeHead;

        while (!vec.empty()){
            curNode->next = vec[0];
            pop_heap(vec.begin(), vec.end(), HeapCompare);
            vec.pop_back();
            curNode = curNode->next;
        }
        return mergeHead;
    }
};
