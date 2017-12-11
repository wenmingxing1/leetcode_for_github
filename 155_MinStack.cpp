//剑指offer第21题
#include<iostream>
#include<stack>
using namespace std;
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {};
    ~MinStack() {};
    void push(int x) {
        data.push(x);
        if (mindata.empty() || x <= mindata.top())   //或运算不能交换位置，同时等号也不能丢
            mindata.push(x);
    }

    void pop() {
        if (data.top() == mindata.top())
            mindata.pop();
        data.pop();
    }

    int top() {
        return data.top();
    }

    int getMin() {
        return mindata.top();
    }
private:
    std::stack<int> data;
    std::stack<int> mindata;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

int main()
{
    MinStack minstack;
    minstack.push(0);
    minstack.push(1);
    cout << minstack.top() << endl;
    minstack.push(-1);
    minstack.push(0);
    cout << minstack.getMin() << endl;

    return 0;
}
