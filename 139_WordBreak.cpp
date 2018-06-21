#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int length = s.size();
        bool dp[length+1] = {false};
        dp[0] = true;

        for (int i = 0; i < length+1; ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && Contain(wordDict, s.substr(j, i-j)))
                    dp[i] = true;
            }
        }
        return dp[length];
    }
private:
    bool Contain(vector<string>& wordDict, string str) {
        for (auto s : wordDict) {
            if (s == str)
                return true;
        }
        return false;
    }
};

int main() {
    string s = "catsandog";
    vector<string> wordDict = {"cats", "dog", "sand", "and", "cat"};

    Solution solu;
    cout << solu.wordBreak(s, wordDict) << endl;

    string s2 = "leetcode";
    vector<string> wordDict2 = {"leet", "code"};
    cout << solu.wordBreak(s2, wordDict2) << endl;

    return 0;
}
