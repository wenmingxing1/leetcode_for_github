#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int length = s.size();
        bool dp[length][length];
        int start = 0;
        int end = 0;
        int len = 1;

        for (int i = 0; i < length; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (j == i) dp[j][i] = true;
                else if (j == i-1) dp[j][i] = (s[j]==s[i]);
                else dp[j][i] = (s[j]==s[i]) && dp[j+1][i-1];

                if (dp[j][i] && len < i-j+1) {
                    len = i-j+1;
                    start = j;
                    end = i;
                }
            }
        }

        /*
        int start = 0;
        int end = 0;
        int len = 1;
        for (int i = 0; i < length; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (dp[j][i] && len < i-j+1) {
                    len = i-j+1;
                    start = j;
                    end = i;
                }
            }
        }
        */

        string res(s.begin()+start, s.begin()+end+1);
        return res;
    }
};

int main() {
    Solution solu;
    string test1 = "babad";
    string test2 = "cbbd";

    cout << solu.longestPalindrome(test1) << endl;
    cout << solu.longestPalindrome(test2) << endl;

    return 0;
}
