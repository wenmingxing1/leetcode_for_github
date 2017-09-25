//利用二分查找，这个return low的这种方式能解决插入位置问题。
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high){
            int middle = low + (high - low) / 2;    //一定要使用这种方式，因为如果使用low+high可能超过int范围
            if (target > nums[middle]){
                low = middle + 1;
            }
            else{
                high = middle - 1;
            }
        }
        return low;
    }
};
