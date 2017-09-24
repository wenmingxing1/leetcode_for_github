#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n < 2)
            return n;

        int len = 0;
        for (int i = 1; i < n; ++i){
            if (nums[len] != nums[i]){      //如果相等就向下迭代，找到第一个不相等的，赋值到len的下一个位置
                ++len;
                nums[len] = nums[i];
            }
        }
        return len + 1;
    }
};

int main()
{
    vector<int> nums = {1,1,2,2,4,4,4,5};
    Solution solu;
    int result = solu.removeDuplicates(nums);

    cout << result << endl;
    return 0;
}
