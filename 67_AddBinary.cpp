#include<iostream>
#include<string>

using namespace std;


class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int carry = '0';   //记录进位
        int index1 = a.size()-1;
        int index2 = b.size()-1;

        while (index1 >= 0 || index2 >= 0) {
            int a_num = index1 >= 0 ? a[index1--]-'0' : 0;
            int b_num = index2 >= 0 ? b[index2--]-'0' : 0;
            int sum = a_num + b_num + carry;
            carry = sum / 2;    //三个相加对2取商得到进位
            sum = sum % 2;  //对2取模得到本位的大小
            res = to_string(sum) + res;
        }

        if (carry == 1) {
            res = '1' + res;
        }
        return res;
    }
};

