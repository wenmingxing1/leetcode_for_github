class Solution {
public:
    //��ָoffer40��򻯰棬������������
    int singleNumber(vector<int>& nums) {
        int res = 0;
        int length = nums.size();

        for (int i = 0; i < length; ++i){
            res = res ^ nums[i];
        }
        return res;
    }
};
