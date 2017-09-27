class Solution
{
    vector<int> getRow(int rowIndex)
    {
        vector<int> prev;
        for (int i = 0; i <= rowIndex; ++i)
        {
            vector<int> now;
            now.push_back(1);
            for (int j = 1; j < i; ++j)
            {
                now.push_back(prev[j - 1] + prev[j]);
            }
            if (i >= 1)
                now.push_back(1);
            prev = now;
        }
        return prev;
    }
};
