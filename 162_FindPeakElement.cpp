//利用二分查找
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int length = nums.size();
        int start = 0;
        int end = length - 1;
        while (start < end){
            int middle = start + (end - start) / 2;
            if (nums[middle] > nums[middle+1]){
                end = middle;
            }
            else if (nums[middle] < nums[middle+1]){
                start = middle + 1;
            }
        }
        return start;

    }
};
