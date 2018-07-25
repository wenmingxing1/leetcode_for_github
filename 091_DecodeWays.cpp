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
            if (s[i] == '0') dp[i] = 0;     //ֻ��һ������Ϊ0�����ǲ��ܷ����

            //����ܺ�ǰһ�����С��26������������������룬�Լ�����ǰһ������
            if (s[i-1] == '1' || (s[i-1] <= '2' && s[i] <= '6')) dp[i+1] = dp[i]+dp[i-1];
            else dp[i+1] = dp[i];   //�����ֻ�ܵ�������
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
