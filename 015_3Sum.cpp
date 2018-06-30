class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() < 3)
            return vector<vector<int>>();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i) {
            int start = i+1; int end = nums.size() - 1;
            while (start < end) {
                if (nums[start]+nums[end] == -nums[i]) {
                    vector<int> temp;
                    temp.push_back(nums[start]);
                    temp.push_back(nums[end]);
                    temp.push_back(nums[i]);
                    res.push_back(temp);
                    ++start; --end;
                    //跳过重复元素
                    while (start < end && nums[start] == nums[start-1]) ++start;
                    while (start < end && nums[end] == nums[end+1]) --end;
                }
                else if (nums[start]+nums[end] < -nums[i]) {
                    ++start;
                }
                else {
                    --end;
                }

            }

            //跳过重复元素
            while (i < end && nums[i+1] == nums[i]) ++i;
        }
        return res;
    }
};
