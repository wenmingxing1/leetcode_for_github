#include<iostream>

using namespace std;

class Solution {
public:
    /* ��n=3Ϊ��������1Ϊrootʱ����������0���ڵ㣬��������2���ڵ�
     * ����1Ϊrootʱ����dp[0]*dp[2]�֣�����2Ϊrootʱ����������1���ڵ㣬
     * ��������1���ڵ㣬��dp[1]*dp[1]������3Ϊrootʱ����������2���ڵ㣬
     * ��������0���ڵ㣬��dp[2]*dp[0]
     * dp[3] = dp[0]*dp[2] + dp[1]*dp[1] + dp[2]*dp[0]
     * dp[i] = dp[0]*dp[i-1] + dp[1]*dp[i-2] + ... + dp[i-1][0]
    */
    int numTrees(int n) {
        int dp[n+1] = {0};
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                dp[i] += dp[j]*dp[i-1-j];
            }
        }
        return dp[n];
    }
};

int main() {
    Solution solu;
    cout << solu.numTrees(3) << endl;

    return 0;
}
