#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int length = nums.size();
        if (length <= 1) return;

        int index = length-2;
        while (index >= 0 && nums[index] >= nums[index+1]) {
            --index;
        }

        if (index == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        int i = length - 1;
        for (; i > index; --i) {
            if (nums[i] > nums[index]) break;
        }

        swap(nums[index], nums[i]);
        reverse(nums.begin()+index+1, nums.end());
        return;
    }
};
