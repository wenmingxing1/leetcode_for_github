#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        string res;
        if (num1 == "0" || num2 == "0") return "0";
        int index = num2.size() - 1;
        int moveBit = 0;

        while (index >= 0) {
            res = add(res, moveBitFunction(multiplyOne(num1, num2[index]-'0'), moveBit));
            index--;
            ++moveBit;
        }
        return res;
    }

private:
    string multiplyOne(string num, int k) {
        int carry = 0;
        int index = num.size() - 1;

        string res;

        while (index >= 0) {
            int numInt = index >= 0 ? num[index--]-'0' : 0;
            int multi = numInt * k + carry;
            carry = multi / 10;
            multi = multi % 10;
            res = to_string(multi) + res;
        }

        if (carry != 0) {
            res = to_string(carry) + res;
        }
        return res;
    }

    string add(string num1, string num2) {
        int carry = 0;
        int index1 = num1.size() - 1;
        int index2 = num2.size() - 1;
        string res;

        while (index1 >= 0 || index2 >= 0) {
            int num1Int = index1 >= 0 ? num1[index1--]-'0' : 0;
            int num2Int = index2 >= 0 ? num2[index2--]-'0' : 0;

            int sum = num1Int + num2Int + carry;

            carry = sum / 10;
            sum = sum % 10;

            res = to_string(sum) + res;
        }
        if (carry != 0)
            res = to_string(carry) + res;

        return res;
    }

    string moveBitFunction(string num, int moveBit) {
        string res = num;
        while (moveBit) {
            res += '0';
            --moveBit;
        }
        return res;
    }
};
