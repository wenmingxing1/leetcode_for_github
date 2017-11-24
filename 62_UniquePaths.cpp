#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    //动态规划问题，找到位置与前面位置的关系
    int uniquePaths(int m, int n)
    {
        if (m <= 0 || n <= 0)
            return 0;
        vector<int> res(n, 1);
        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                res[j] += res[j-1];
            }
        }
        return res[n-1];
    }
};

int main()
{
    Solution solu;
    cout << solu.uniquePaths(3,3) << endl;

    return 0;
}
