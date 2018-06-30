#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> Subsets(vector<int> num)
    {
        vector<vector<int>> res;
        vector<int> temp;
        if (num.size() <= 0)
            return res;
        getSubsets(num, res, temp, 0);
        return res;
    }
private:
    //Ñ­»·¼ÓµÝ¹é¹¹³É»ØËÝ·¨
    void getSubsets(vector<int>num, vector<vector<int>>& res, vector<int>& temp, int start)
    {
        res.push_back(temp);
        for (int i = start; i < num.size(); ++i)
        {
            temp.push_back(num[i]);
            getSubsets(num, res, temp, i+1);
            temp.pop_back();
        }
    }
};

int main()
{
    vector<int> num = {1,2,3};
    Solution solu;
    vector<vector<int>> res = solu.Subsets(num);

    for (int i = 0; i < res.size(); ++i)
    {
        for (int j = 0; j < res[i].size(); ++j)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
