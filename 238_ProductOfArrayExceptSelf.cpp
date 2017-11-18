class Solution {
public:
    //剑指offer第52题，如果采用暴力相乘的方法，时间复杂度为n2，所以可以拆分原数组
    vector<int> productExceptSelf(vector<int>& nums) {
        int count = nums.size();
        vector<int> res(count, 1);
        vector<int> left(count, 1);
        vector<int> right(count, 1);

        for (int i = 1; i < count; ++i){
            left[i] = left[i-1] * nums[i-1];
        }

        for (int i = count - 2; i >= 0; --i){
            right[i] = right[i+1] * nums[i+1];
        }

        for (int i = 0; i < count; ++i){
            res[i] = left[i] * right[i];
        }
        return res;
    }
};
