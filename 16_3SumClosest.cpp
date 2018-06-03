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
        int diff = abs(res - target);

        for (int i = 0; i < length-2; ++i) {

            int left = i+1;
            int right = length - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                int newdiff = abs(sum - target);
                if (newdiff < diff) {
                    diff = newdiff;
                    res = sum;
                }

                if (sum < target) ++left;
                else --right;
            }
        }
        return res;
    }
};

int main() {
    vector<int> vec = {-1,2,1,-4};
    Solution solu;

    cout << solu.threeSumClosest(vec,1);

    return 0;
}
