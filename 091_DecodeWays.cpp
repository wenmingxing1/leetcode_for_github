#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int length = s.size();
        if (length == 0 || s[0] == '0') return 0;

        vector<int> dp(length+1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 1; i < length; ++i) {
            if (s[i] == '0') dp[i] = 0;     //只有一个单独为0，则是不能翻译的

            //如果能和前一个组成小于26的数，则包含单独翻译，以及加上前一个翻译
            if (s[i-1] == '1' || (s[i-1] <= '2' && s[i] <= '6')) dp[i+1] = dp[i]+dp[i-1];
            else dp[i+1] = dp[i];   //否则就只能单独翻译
        }
        return dp[length];
    }
};

int main() {
    Solution solu;
    string test = "226";
    cout << solu.numDecodings(test) << endl;

    return 0;
}
