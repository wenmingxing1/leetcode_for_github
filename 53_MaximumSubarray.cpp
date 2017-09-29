//��̬�滮��⣬ά��һ��ȫ�����ţ�һ���ֲ�����
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
