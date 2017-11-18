class Solution {
public:
    //��ָoffer��52�⣬������ñ�����˵ķ�����ʱ�临�Ӷ�Ϊn2�����Կ��Բ��ԭ����
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
