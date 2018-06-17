#include<iostream>
#include<math.h>
#include<algorithm>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int res = 0;

        while (x) {
            int num = x % 10;
            //ÅĞ¶ÏÊÇ·ñÒç³ö
            if (abs(res) > INT_MAX / 10) return 0;
            res = res * 10 + num;
            x = x / 10;
        }
        return res;
    }
};

int main() {
    Solution solu;
    int test1 = 123;
    int test2 = -123;
    int test3 = 120;
    int test4 = 1534236469;
    int test5 = -2147483412;

    cout << solu.reverse(test1) << " " << solu.reverse(test2) << " " << solu.reverse(test3) << " "
    << solu.reverse(test4) << " " << solu.reverse(test5) << endl;

    return 0;
}
