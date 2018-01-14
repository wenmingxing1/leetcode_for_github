//此题需要一直保证一个queue为空，才能完成pop操作（非空queue中剩下的最后一个元素）
//因为需要保证一个queue为空，所以，push操作也有所不同
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        if (queue1.empty())
            queue2.push(x);
        else
            queue1.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    //必有一个队列为空
    int pop() {
        int res = 0;
        if (queue1.empty()) {
            while (queue2.size() > 1) {
                queue1.push(queue2.front());
                queue2.pop();
            }
            res = queue2.front();
            queue2.pop();
        }
        else if (queue2.empty()) {
            while (queue1.size() > 1) {
                queue2.push(queue1.front());
                queue1.pop();
            }
            res = queue1.front();
            queue1.pop();
        }
        return res;
    }

    /** Get the top element. */
    //利用已有的pop
    int top() {
        int res = 0;
        res = pop();
        push(res);      //再装进去，因为每次装进去都是
        return res;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return (queue1.empty() && queue2.empty());
    }
private:
    queue<int> queue1;
    queue<int> queue2;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
