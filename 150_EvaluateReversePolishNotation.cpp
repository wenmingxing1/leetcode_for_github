#include<iostream>
#include<vector>
#include<stack>
#include<string>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int length = tokens.size();
        if (length == 0) return 0;

        stack<int> help;

        for (int i = 0; i < length; ++i) {
            if (isSymbol(tokens[i])) {
                int temp1 = help.top();
                help.pop();
                int temp2 = help.top();
                help.pop();
                //cout << temp1 << " " << temp2 << endl;

                int temp = 0;
                if (tokens[i]=="+")
                    temp = temp2+temp1;
                if (tokens[i]=="-")
                    temp = temp2-temp1;
                if (tokens[i]=="*")
                    temp = temp2*temp1;
                if (tokens[i]=="/")
                    temp = temp2/temp1;

                //cout << temp << endl;

                help.push(temp);
            }
            else {
                help.push(str2Int(tokens[i]));
            }
        }
        return help.top();
    }

private:
    bool isSymbol(string str) {
        if (str == "+" || str == "-" || str == "*" || str == "/")
            return true;
        else return false;
    }

    //也可以直接使用stoi函数
    int str2Int(string& str) {
        int res = 0;
        int start = 0;
        bool isPositive = true;
        if (str[start] == '+')
            ++start;
        if (str[start] == '-') {
            isPositive = false;
            ++start;
        }

        for (int i = start; i < str.size(); ++i) {
            res = res * 10 + (str[i] - '0');
        }

        if (!isPositive)
            return 0-res;
        else return res;
    }
};

int main() {
    Solution solu;
    vector<string> test1 = { "2", "1", "+", "3", "*" };
    vector<string> test2 = { "4", "13", "5", "/", "+" };

    //cout << solu.evalRPN(test1) << endl;
    cout << solu.evalRPN(test2) << endl;

    return 0;
}
