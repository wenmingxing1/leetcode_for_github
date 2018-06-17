#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    int rob(vector<int>& nums) {
        int length = nums.size();
        if (length == 0) return 0;
        if (length == 1) return nums[0];
        if (length == 2) return max(nums[0], nums[1]);

        vector<int> dp1(length-1, 0);
        vector<int> dp2(length, 0);

        dp1[0] = nums[0];
        dp1[1] = max(nums[0], nums[1]);

        for (int i = 2; i < length-1; ++i) {
            dp1[i] = max(dp1[i-1], dp1[i-2]+nums[i]);
        }

        dp2[0] = 0;
        dp2[1] = nums[1];
        dp2[2] = max(nums[1], nums[2]);
        for (int i = 3; i < length; ++i) {
            dp2[i] = max(dp2[i-1], dp2[i-2]+nums[i]);
        }

        return max(dp1[length-2], dp2[length-1]);
    }
};

int main() {
    Solution solu;
    vector<int> test1 = {2,3,2};
    vector<int> test2 = {1,2,3,1};

    cout << solu.rob(test1) << " " << solu.rob(test2) << endl;

    return 0;
}
