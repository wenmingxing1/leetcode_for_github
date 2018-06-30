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
        int c = digit; // carry, 进位
        for (auto it = digits.rbegin(); it != digits.rend(); ++it) {    //反向迭代器
            *it += c;
            c = *it / 10;       //判断是否有进位，如果有进位则将进位作为下一位的加数
            *it %= 10;
        }
        if (c > 0)      //如果最后(最高位)有进位，则在begin处插入1
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
