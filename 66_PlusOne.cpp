#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        add(digits, 1);
        return digits;
    }
private:
    // 0 <= digit <= 9
    void add(vector<int> &digits, int digit) {
        int c = digit; // carry, ��λ
        for (auto it = digits.rbegin(); it != digits.rend(); ++it) {    //���������
            *it += c;
            c = *it / 10;       //�ж��Ƿ��н�λ������н�λ�򽫽�λ��Ϊ��һλ�ļ���
            *it %= 10;
        }
        if (c > 0)      //������(���λ)�н�λ������begin������1
            digits.insert(digits.begin(), 1);
    }
};

int main()
{
    vector<int> one = {9};
    Solution solu;
    solu.plusOne(one);

    for (int i = 0; i < 2; ++i)
    {
        cout << one[i];
    }

    return 0;
}
