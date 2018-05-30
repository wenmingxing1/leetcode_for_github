#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int res = 0;

        int row = triangle.size();
        vector<vector<int>> dp(row, vector<int>(row, 0));

        dp[0][0] = triangle[0][0];
        for (int i = 1; i < row; ++i) {
            dp[i][0] = dp[i-1][0] + triangle[i][0];
            dp[i][i] = dp[i-1][i-1] + triangle[i][i];
        }

        res = dp[row-1][0];

        for (int i = 2; i < row; ++i) {
            for (int j = 1; j < row-1; ++j) {
                if (i != j)
                    dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
            }
        }

        for (int i = 0; i < row; ++i) {
            if (dp[row-1][i] < res)
                res = dp[row-1][i];
        }


        for (int i = 0; i < row; ++i) {
            cout << dp[row-1][i] << " ";
        }


        return res;
    }
};

int main() {
    Solution solu;
    vector<vector<int>> test1 = { {-1}, {2,3}, {1,-1,-3} };
    vector<vector<int>> test2 = { {2}, {3,4}, {6,5,7}, {4,1,8,3} };
    vector<vector<int>> test3 = {{-2},{5,2},{-3,2,7},{8,7,2,-8},{7,5,3,8,-1},{-7,-2,-2,0,-1,6},{4,7,7,-9,9,8,2},{-5,-8,-1,-1,6,7,3,-5},{4,1,-8,-7,-1,5,7,-8,3},{-7,-8,-8,0,1,-3,-4,-8,-6,9},{-7,-9,5,1,-8,6,9,0,-1,6,9},{0,-3,-3,-2,-1,6,-7,-7,4,3,-5,2}};
    cout << solu.minimumTotal(test1) << endl;
    cout << solu.minimumTotal(test2) << endl;
    cout << solu.minimumTotal(test3) << endl;

    return 0;
}
