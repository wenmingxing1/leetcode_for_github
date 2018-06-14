#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        string res;
        int index1 = num1.size() - 1;
        int index2 = num2.size() - 1;

        int carry = 0;

        while (index1 >= 0 || index2 >= 0) {
            int num1Int = (index1 >= 0) ? num1[index1--]-'0' : 0;
            int num2Int = (index2 >= 0) ? num2[index2--]-'0' : 0;

            int sum = num1Int + num2Int + carry;
            carry = sum / 10;
            sum = sum % 10;
            res = to_string(sum) + res;
        }

        if (carry) {
            res = to_string(carry) + res;
        }
        return res;
    }
};
