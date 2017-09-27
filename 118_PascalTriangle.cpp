class Solution
{
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> result;
        vector<int> prev;

        for (int i = 1; i <= numRows; ++i)  //i与j的起始都是1，因为0的位置已经有1了
        {
            vector<int> now;
            now.push_back[1];
            for (int j = 1; j < i - 1; ++j)     //j解决内部vector的除去首尾两个1的其他元素，所以j<i-1
            {
                now.push_back(prev[j - 1] + prev[j])    //杨辉三角特性
            }
            if (i > 1)      //补上最后一个1.
                now.push_back(1);

            result.push_back(now);
            prev = now;
        }
        return result;
    }
};
