class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int length = nums.size();
        int sum = 0;
        int result = nums[0];
        for (int i = 0; i < length; ++i){
            sum += nums[i];
            result = max(result, sum);
            sum = max(sum, 0);
        }
        return result;

    }

private:
    int max(int i, int j){
        return i >= j ? i : j;
    }
};
