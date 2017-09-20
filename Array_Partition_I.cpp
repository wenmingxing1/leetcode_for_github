//先排序，再选奇数位置相加
#include<iostream>
#include<vector>
#include<stdlib.h>

using namespace std;

class Solution
{
public:
    int arrayPairSum(vector<int>& nums)
    {
        int result = 0;
        QuickSort(nums, 0, nums.size());

        for (int i = 0; i < nums.size(); i = i + 2)
        {
            result = result + nums[i];
        }
        return result;

    }
private:
    void Swap(int *i, int *j)
    {
        int temp;
        temp = *i;
        *i = *j;
        *j = temp;
    }

    int RandomInRange(int start, int end)
    {
        if (end > start)
        {
            return start + rand() % (end - start);
        }
        return 0;
    }

    int Partition(vector<int>& nums, int start, int end)
    {
        int small = start - 1;
        //int end = length - 1;
        int index = RandomInRange(start, end);

        Swap(&nums[index], &nums[end]);

        for (int i = start; i < end; ++i)
        {
            if (nums[i] < nums[end])
            {
                ++small;
                if (small != i)
                    Swap(&nums[small], &nums[i]);
            }
        }

        ++small;
        Swap(&nums[end], &nums[small]);

        return small;
    }

    void QuickSort(vector<int>& nums, int start, int end)
    {
        if (start == end)
            return;

        int index = Partition(nums, start, end);
        if (index > start)
            QuickSort(nums, start, index - 1);
        if (index < end)
            QuickSort(nums, index + 1, end);
    }
};

int main()
{
    Solution solu;
    vector<int> nums = {1,4,3,2};

    cout << solu.arrayPairSum(nums) << endl;

    return 0;

}
