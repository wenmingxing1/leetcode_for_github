#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> res;
        vector<int> temp;
        if (n <= 0 || k <= 0 || k > n)
            return res;
        combinations(n,k,1,0,res,temp);
        return res;
    }
private:
    //Ñ­»·¼ÓµÝ¹é£¬»ØËÝ·¨
    void combinations(int n, int k, int start, int num, vector<vector<int>>& res, vector<int>& temp)
    {
        if (num == k)
            res.push_back(temp);
        for (int i = start; i <= n; ++i)
        {
            temp.push_back(i);
            combinations(n,k,i+1,num+1,res,temp);
            temp.pop_back();
        }
    }
};

int main()
{
    Solution solu;
    vector<vector<int>> res = solu.combine(4,2);
    //cout << res.size() << endl;


    for (int i = 0; i < res.size(); ++i)
    {
        for (int j = 0; j < res[0].size(); ++j)
            cout << res[i][j] << " ";
        cout << endl;
    }

    return 0;
}
