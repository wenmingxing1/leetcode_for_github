/*
class Solution {
public:
    //利用set，判断，set的底层实现是红黑树
    bool containsDuplicate(vector<int>& nums) {
        set<int> res(nums.begin(), nums.end());
        return nums.size() > res.size();
    }
};
*/

class Solution {
    public:
    //直接利用排序判断，需改变数组，空间复杂度为O(1)
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); ++i){
            if (nums[i] == nums[i-1])
                return true;
        }
        return false;
    }
};
