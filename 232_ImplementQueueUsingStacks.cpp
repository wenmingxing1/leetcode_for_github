//��ָoffer��7��
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
        if (!stack2.empty())    //���stack2�в�Ϊ�գ��򷵻�ֱ�ӵ�����Ԫ��
        {
            res = stack2.top();     //��Ϊstack��pop����ֵΪvoid��������Ҫ�м�����洢
            stack2.pop();
            return res;
        }
        //���򣬽�stack1�е�Ԫ�ص���ѹ�뵽stack2�У��ٵ���stack2�е�Ԫ��
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
        //���������Ѿ���ɵ�pop
        int res = pop();
        stack2.push(res);   //���·Ż�ȥ
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
