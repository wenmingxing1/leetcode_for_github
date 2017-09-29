class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int middle = left;          //如果反转为0，则不满足下面的循环条件，直接返回left的值

        while (nums[left] >= nums[right]){
            if (right - left == 1){     //循环结束条件
                middle = right;
                break;
            }
            middle = left + (right - left) / 2;
            if (nums[right] == nums[left] && nums[left] == nums[middle]){       //如果三个值相等，则无法判断middle在那一部分，只能顺序查找
                return *min_element(nums.begin(), nums.end());
            }

            if (nums[middle] >= nums[left]){
                left = middle;
            }
            if (nums[middle] <= nums[right]){
                right = middle;
            }
        }
        return nums[middle];
    }
};
