class Solution
{
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> result;
        vector<int> prev;

        for (int i = 1; i <= numRows; ++i)  //i��j����ʼ����1����Ϊ0��λ���Ѿ���1��
        {
            vector<int> now;
            now.push_back[1];
            for (int j = 1; j < i - 1; ++j)     //j����ڲ�vector�ĳ�ȥ��β����1������Ԫ�أ�����j<i-1
            {
                now.push_back(prev[j - 1] + prev[j])    //�����������
            }
            if (i > 1)      //�������һ��1.
                now.push_back(1);

            result.push_back(now);
            prev = now;
        }
        return result;
    }
};
