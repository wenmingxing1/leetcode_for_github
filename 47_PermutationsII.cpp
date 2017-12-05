//剑指offer28题
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        permuteUniqueCore(nums, 0, res);
        return res;
    }
private:
    void permuteUniqueCore(vector<int>& nums, int begin, vector<vector<int>>& res){
        if (begin == nums.size()){
            res.push_back(nums);
        }
        else{
            for (int i = begin; i < nums.size(); ++i){
                if (!duplicate(nums, begin, i)){
                    swap(nums[begin], nums[i]);
                    permuteUniqueCore(nums, begin+1, res);
                    swap(nums[begin], nums[i]);
                }
            }
        }
    }

    //判断是否有重复，如果begin到i中已经有了与i相同的元素，则不需要交换begin与i元素了，因为之前已经交换过了
    bool duplicate(vector<int>& nums, int begin, int end){
        for (int i = begin; i < end; ++i){
            if (nums[i] == nums[end])
                return true;
        }
        return false;
    }

};
