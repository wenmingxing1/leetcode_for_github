#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        int colend = n;
        int rowend = n;
        int colstart = 0;
        int rowstart = 0;
        int index = 1;
        vector<vector<int>> res(n, vector<int>(n,0));   //初始化一个二维数组

        while (index <= n*n)
        {
            for (int i = colstart; i < colend; ++i)
            {
                res[rowstart][i] = index;
                ++index;
            }
            ++rowstart;
            for (int i = rowstart; i < rowend; ++i)
            {
                res[i][colend-1] = index;
                ++index;
            }
            --colend;
            for (int i = colend-1; i >= colstart; --i)
            {
                res[rowend-1][i] = index;
                ++index;
            }
            --rowend;
            for (int i = rowend-1; i >= rowstart; --i)
            {
                res[i][colstart] = index;
                ++index;
            }
            ++colstart;
        }
        return res;
    }
};

int main() {
    Solution solu;
    vector<vector<int>> res = solu.generateMatrix(3);

    for (auto v : res) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}
