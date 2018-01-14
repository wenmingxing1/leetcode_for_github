//剑指offer第7题
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        stack1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int res = 0;
        if (!stack2.empty())    //如果stack2中不为空，则返回直接弹出的元素
        {
            res = stack2.top();     //因为stack的pop返回值为void，所以需要中间变量存储
            stack2.pop();
            return res;
        }
        //否则，将stack1中的元素弹出压入到stack2中，再弹出stack2中的元素
        else {
            while(!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
            res = stack2.top();
            stack2.pop();
            return res;
        }
    }

    /** Get the front element. */
    int peek() {
        //可以利用已经完成的pop
        int res = pop();
        stack2.push(res);   //重新放回去
        return res;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return (stack1.empty() && stack2.empty());
    }
private:
    stack<int> stack1;
    stack<int> stack2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
