class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();    //如果k大于数组长度
        if (nums.size() == 1)
            return;
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }
private:
    void reverse(vector<int>& nums, int start, int end){
        while (start < end){
            Swap(&nums[start], &nums[end]);
            start++;
            end--;
        }
    }
    void Swap(int* i, int* j){
        int temp = *i;
        *i = *j;
        *j = temp;
    }

};
