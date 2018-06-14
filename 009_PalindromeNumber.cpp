#include<iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int left = x;
        int right = 0;

        while (x) {
            int temp = x % 10;
            right = right * 10 + temp;
            x = x / 10;
        }
        return left == right;
    }
};

int main() {
    Solution solu;
    int test1 = 121;
    int test2 = -121;
    int test3 = 10;

    cout << solu.isPalindrome(test1) << "," << solu.isPalindrome(test2) << ","
    << solu.isPalindrome(test3) << endl;

    return 0;
}
