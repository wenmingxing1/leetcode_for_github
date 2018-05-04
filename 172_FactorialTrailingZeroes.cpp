/*注意25中其实包含了两个5*/
#include<iostream>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        //2的个数肯定是多于5的个数的，所以直接计算5的个数，再将25这种情况考虑进去即可
        while (n) {
            count += n/5;   //5的个数；
            n /= 5;     //25的情况；
        }
        return count;
    }
};

int main() {
    int n;
    cin >> n;
    Solution s;
    cout << s.trailingZeroes(n) << endl;

    return 0;
}
