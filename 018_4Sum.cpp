#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int length = nums.size();
        if (length < 4) return vector<vector<int>>();
        set<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < length - 3; ++i) {
            for (int j = i+1; j < length - 2; ++j) {
                int tempTarget = target - nums[i] - nums[j];
                int start = j+1;
                int end = length - 1;
                while (start < end) {
                    if (nums[start]+nums[end] == tempTarget) {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[start]);
                        temp.push_back(nums[end]);

                        res.insert(temp);
                        ++start; --end;
                    }
                    else if (nums[start]+nums[end] < tempTarget)
                        ++start;
                    else --end;
                }
            }
        }
        vector<vector<int>> resVec(res.begin(), res.end());
        return resVec;
    }
};

int main() {
    Solution solu;
    vector<int> nums = {1,0,-1,0,-2,2};
    vector<int> nums2 = {0,0,0,0};
    vector<int> nums3 = {-3,-2,-1,0,0,1,2,3};

    vector<vector<int>> res = solu.fourSum(nums3, 0);

    for (auto vec : res) {
        for (auto i : vec)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}
