#include<iostream>
#include<string>
#include<stack>

using namespace std;

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

int main() {
    string strTest1 = "{}";
    string strTest2 = "[";
    string strTest3 = "[{}]()";

    Solution s;
    cout << s.isValid(strTest1) << " " << s.isValid(strTest2) << " " << s.isValid(strTest3) << endl;

    return 0;
}
