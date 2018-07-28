#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr) return nullptr;

        sortListCore(head, nullptr);

        return head;

    }
private:
    ListNode* partation(ListNode* node1, ListNode* node2) {
        int value = node1->val;
        ListNode* small = node1;
        ListNode* index = node1->next;

        while (index != node2) {
            if (index->val < value) {
                small = small->next;
                if (small != index)
                    swap(small->val, index->val);
            }
            index = index->next;
        }

        swap(small->val, node1->val);
        return small;
    }

    void sortListCore(ListNode* start, ListNode* end) {
        if (start != end) {
            ListNode* part = partation(start, end);
            sortListCore(start, part);
            sortListCore(part->next, end);
        }
    }
};

int main() {
    Solution solu;

    ListNode* node1 = new ListNode(3);
    ListNode* node2 = new ListNode(5);
    ListNode* node3 = new ListNode(1);
    ListNode* node4 = new ListNode(2);
    ListNode* node5 = new ListNode(4);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = nullptr;



    ListNode* temp = solu.sortList(node1);
    while (temp) {
        cout << temp->val << ",";
        temp = temp->next;
    }

    //cout << temp->val << endl;

    return 0;
};
