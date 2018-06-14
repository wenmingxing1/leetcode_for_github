#include<iostream>

using namespace std;

//常规做法
class Solution1 {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;

        while (n) {
            if (n % 2 == 1) ++res;
            n = n / 2;
        }
        return res;
    }
};

//位的做法
class Solution2 {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            res += (n&1);
            n = n >> 1;
        }
        return res;
    }
};

int main() {
    Solution1 solu1;
    Solution2 solu2;
    cout << solu1.hammingWeight(11) << endl;
    cout << solu2.hammingWeight(11) << endl;

    return 0;
}
