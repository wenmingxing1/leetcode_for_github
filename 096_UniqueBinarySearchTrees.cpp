#include<iostream>

using namespace std;

class Solution {
public:
    /* 以n=3为例，当以1为root时，左子树有0个节点，右子树有2个节点
     * 则以1为root时，有dp[0]*dp[2]种；当以2为root时，左子树有1个节点，
     * 右子树有1个节点，则dp[1]*dp[1]，当以3为root时，左子树有2个节点，
     * 右子树有0个节点，则dp[2]*dp[0]
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
