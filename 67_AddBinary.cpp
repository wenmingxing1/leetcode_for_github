#include<iostream>
#include<string>

using namespace std;


class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int carry = '0';   //��¼��λ
        int index1 = a.size()-1;
        int index2 = b.size()-1;

        while (index1 >= 0 || index2 >= 0) {
            int a_num = index1 >= 0 ? a[index1--]-'0' : 0;
            int b_num = index2 >= 0 ? b[index2--]-'0' : 0;
            int sum = a_num + b_num + carry;
            carry = sum / 2;    //������Ӷ�2ȡ�̵õ���λ
            sum = sum % 2;  //��2ȡģ�õ���λ�Ĵ�С
            res = to_string(sum) + res;
        }

        if (carry == 1) {
            res = '1' + res;
        }
        return res;
    }
};

