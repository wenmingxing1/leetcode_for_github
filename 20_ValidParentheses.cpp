#include<iostream>
#include<string>
#include<stack>

using namespace std;

//使用栈的方法
class Solution{
public:
    bool isValid(const string& str) {
        if (str.size() == 0) return true;
        stack<char> help;
        for (auto ch : str) {
            if (!help.empty()) {
                if (help.top() == '[' && ch == ']') help.pop();
                else if (help.top() == '(' && ch == ')') help.pop();
                else if (help.top() == '{' && ch == '}') help.pop();
                else help.push(ch);
            }
            else
                help.push(ch);
        }
        return help.empty();
    }
};

//不用栈的方法
class  Solution2 {
public:
    bool isValid(const string& str) {
        if (str.size() == 0) return true;
        int res = 0;
        for (auto ch:str) {
            if (ch == '{' || ch == '(' || ch == '[') res+=1;
            else if (ch == '}' || ch == ')' || ch == ']') res-=1;
            else res+=0;

            if (ch < 0) return false;
        }
        return res == 0;
    }
};

int main() {
    string strTest1 = "{}";
    string strTest2 = "[";
    string strTest3 = "[{}]()";

    Solution2 s;
    cout << s.isValid(strTest1) << " " << s.isValid(strTest2) << " " << s.isValid(strTest3) << endl;

    return 0;
}
