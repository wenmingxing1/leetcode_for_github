#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> temp;
        genSubsets(nums, 0, res, temp);
        return res;
    }
private:
    void genSubsets(vector<int>& nums, int start, vector<vector<int>>& res, vector<int>& temp) {
        res.push_back(temp);
        for (int i = start; i < nums.size(); ++i) {
            if (i == start || (i > start && nums[i] != nums[i-1])) {    //进行去重处理
                temp.push_back(nums[i]);
                genSubsets(nums, i+1, res, temp);
                temp.pop_back();
            }
        }
    }
};


int main() {
    vector<int> nums = {1,2,2};
    Solution solu;
    vector<vector<int>> res = solu.subsetsWithDup(nums);

    for (auto v : res) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}
