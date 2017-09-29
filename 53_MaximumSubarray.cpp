//动态规划求解，维护一个全局最优，一个局部最优
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int length = nums.size();

        int global = nums[0];
        int local = nums[0];
        for (int i = 1; i < length; ++i){
            local = max(nums[i], nums[i] + local);
            global = max(global, local);
        }
        return global;
    }
private:
    int max(int i, int j){
        return i >= j ? i : j;
    }

};
