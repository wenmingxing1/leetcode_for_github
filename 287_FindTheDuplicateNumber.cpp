class Solution {
public:
    //Ω£÷∏offer51Ã‚
    int findDuplicate(vector<int>& nums) {
        if (nums.size() == 0)
            return -1;
        for (int i = 0; i < nums.size(); ++i){
            while (nums[i] != i){
                if (nums[i] == nums[nums[i]])
                    return nums[i];
                Swap(&nums[i], &nums[nums[i]]);
            }
        }
    }
private:
    void Swap(int* i, int* j){
        int temp = *i;
        *i = *j;
        *j = temp;
    }
};

