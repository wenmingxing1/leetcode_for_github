//���ö�̬�滮����Ϊ�˷��������ԣ�������Ҫά��һ���ֲ�����һ���ֲ���С
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int length = nums.size();
        int global = nums[0];
        int max_local = nums[0];
        int min_local = nums[0];

        for (int i = 1; i < length; ++i){
            int max_copy = max_local;
            max_local = max(max(nums[i]*max_local, nums[i]), nums[i]*min_local);
            min_local = min(min(nums[i]*max_copy, nums[i]), nums[i]*min_local);
            global = max(max_local, global);
        }
        return global;
    }
private:
    int min(int i, int j){
        return i <= j ? i : j;
    }

    int max(int i, int j){
        return i >= j ? i : j;
    }
};
