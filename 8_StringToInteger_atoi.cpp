#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    //剑指offer49，但考虑的情况更多
    int myAtoi(string str) {
        int size = str.size();
        if (size == 0){
            return 0;
        }

        string::iterator iter = str.begin();

        while (*iter == ' ')    //对于空格的处理
            iter++;

        bool isPositive = true;

        if (*iter == '-'){      //对于正负号的处理
            isPositive = false;
            iter++;
        }
        else if(*iter == '+'){
            iter++;
        }

        double number = 0;      //double是为了方便越界处理
        while (iter != str.end()){      //常规操作
            if (*iter >= '0' && *iter <= '9'){
                number = number * 10 + *iter - '0';
                iter++;
            }
            else
                break;
        }

        if (number > INT_MAX){      //越界处理，和正负号判断
            if (isPositive)
                return INT_MAX;
            else
                return INT_MIN;
        }
        else{
            if (isPositive)
                return number;
            else
                return 0-number;
        }
    }
};

int main()
{
    string str = "-123a5";
    Solution solu;
    cout << solu.myAtoi(str) << endl;

    return 0;
}
