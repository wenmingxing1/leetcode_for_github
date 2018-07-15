#include<iostream>
#include<deque>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

//使用双向队列deque
//另一种方法是，先使用快慢指针找到链表的中点，将链表分为两部分，然后将第二个链表翻转，再完成插入
class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return;

        deque<ListNode*> help;

        ListNode* node = head;

        while (node) {
            help.push_back(node);
            node = node->next;
        }

        bool isfront = true;
        ListNode* newhead = nullptr;

        if (!help.empty()) {
            newhead = help.front();
            help.pop_front();
            isfront = !isfront;
        }

        node = newhead;
        ListNode* temp = nullptr;

        while (!help.empty()) {
            if (isfront) {
                temp = help.front();
                node->next = temp;
                node = temp;
                help.pop_front();
                isfront = !isfront;

                //cout << "temp:" << temp->val << endl;
            }
            else {
                temp = help.back();
                node->next = temp;
                node = temp;
                help.pop_back();
                isfront = !isfront;

                //cout << "temp:" << temp->val << endl;
            }
        }
        temp->next = nullptr;
        head = newhead;
        return;
    }
};

int main() {
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    ListNode* head = node1;

    Solution solu;

    solu.reorderList(head);

    ListNode* node = head;
    while (node) {
        cout << node->val << " ";
        node = node->next;
    }

    return 0;
}
