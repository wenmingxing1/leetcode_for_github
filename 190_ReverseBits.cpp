#include<iostream>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;

        for (int i = 0; i < 32; ++i) {
            res = 2*res + (n%2);
            n = n >> 1;
        }
        return res;
    }
};

int main() {
    Solution solu;
    cout << solu.reverseBits(43261596) << endl;

    return 0;
}
