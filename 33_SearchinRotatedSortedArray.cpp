#include<iostream>
#include<vector>

using namespace std;

//先找到旋转点，再通过二分查找
class Solution1 {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;
        int start = 0;
        int end = nums.size() - 1;
        int mid = searchSmallest(nums);
        if (target == nums[0]) return 0;
        else if (target > nums[0])   return searchCore(nums, start, mid, target);
        else return searchCore(nums, mid, end, target);
    }
private:
    int searchSmallest(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        int mid = left;

        while (left < right) {
            if (left + 1 == right) {
                mid = right;
                break;
            }

            mid = left + (right - left) / 2;
            if (nums[mid] > nums[left]) left = mid;
            if (nums[mid] < nums[left]) right = mid;
        }
        return mid;
    }

    int searchCore(vector<int>& nums, int start, int end, int target) {
        int res = 0;
        int mid = 0;

        while (start <= end) {
            mid = start + (end - start) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] < target)
                start = mid + 1;
            else end = mid - 1;
        }
        return -1;

    }
};

//直接应用二分查找，在查找过程中判断在哪一部分
class Solution2 {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid = left;

        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;

            //mid在左半部分
            if (nums[mid] > nums[right]) {
                if (target < nums[mid] && target >= nums[left])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            //mid在右半部分
            else if (nums[mid] < nums[left]) {
                if (target > nums[mid] && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            //无旋转，直接二分
            else {
                if (target < nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }
        return -1;

    }
};

int main() {
    Solution1 solu1;
    Solution2 solu2;
    vector<int> vec = {4,5,6,7,0,1,2};
    cout << solu1.search(vec, 6) << endl;
    cout << solu2.search(vec, 6) << endl;
    cout << endl;

    cout << solu1.search(vec, 3) << endl;
    cout << solu2.search(vec, 3) << endl;
    cout << endl;

    cout << solu1.search(vec, 4) << endl;
    cout << solu2.search(vec, 4) << endl;
    cout << endl;

    return 0;
}


