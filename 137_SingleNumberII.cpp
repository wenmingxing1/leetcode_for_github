#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int length = nums.size();
        int res = 0;
        for (int i = 0; i < 32; ++i){
            int count = 0;
            int mask = 1 << i;      //分别为1,10,100，... 目的是为了计算第几位

            for (int j = 0; j < length; ++j){   //计算第i位的1的个数
                if ((nums[j] & mask) != 0)      //注意位操作符的优先级很低的问题
                    ++count;
            }

            if (count % 3)  //模3如果等于1，则证明single number此位为1
                res = res | mask;
        }
        return res;
    }
};


int main()
{
    vector<int> nums = {1};
    Solution solu;
    cout << solu.singleNumber(nums) << endl;

    return 0;
}
