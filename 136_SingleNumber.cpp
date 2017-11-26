class Solution {
public:
    //剑指offer40题简化版，利用异或的性质
    int singleNumber(vector<int>& nums) {
        int res = 0;
        int length = nums.size();

        for (int i = 0; i < length; ++i){
            res = res ^ nums[i];
        }
        return res;
    }
};
