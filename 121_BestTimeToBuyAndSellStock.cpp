#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int local = 0;
        int global = 0;
        int length = prices.size();
        if (length > 0)
        {
            for (int i = 0; i < length-1; ++i)
            {
                local = max(local + prices[i+1] - prices[i], 0);    //ά��һ���ֲ����������ֲ��������·�����
                global = max(global, local);    //ά��һ��ȫ�ֱ���
            }
        }
        return global;
    }
private:
    int max(int i, int j)
    {
        return i>j?i:j;
    }
};

int main()
{
    vector<int> prices = {7,1,5,3,6,4};
    Solution solu;
    cout << solu.maxProfit(prices) << endl;

    return 0;
}
