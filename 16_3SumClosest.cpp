#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int length = nums.size();
        if (length < 3) return -1;

        sort(nums.begin(), nums.end());

        int res = nums[0]+nums[1]+nums[2];

        for (int i = 0; i < length; ++i) {
            int temp = target - nums[i];

        }

    }

private:
    int twoSumClosest(vector<int>& nums, int start, int end, int target) {

    }
};
