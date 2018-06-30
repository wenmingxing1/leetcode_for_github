#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;
        int mid = start;

        while (start <= end) {
            mid = start + (end - start) / 2;
            if (nums[mid] == target) return true;

            //ÎÞ·¨ÅÐ¶ÏÊôÓÚÄÄ±ß
            if (nums[mid] == nums[start] && nums[mid] == nums[end])
                return searchLoop(nums, target);

            //left part
            if (nums[mid] > nums[end]) {
                if (nums[mid] > target && target >= nums[start])
                    end = mid - 1;
                else
                    start = mid + 1;
            }
            //right part
            else if (nums[mid] < nums[start]) {
                if (nums[mid] < target && target <= nums[end])
                    start = mid + 1;
                else
                    end = mid - 1;
            }
            else {
                if (nums[mid] < target)
                    start = mid + 1;
                else
                    end  = mid - 1;
            }

        }

        return false;
    }
private:
    bool searchLoop(vector<int>& vec, int target) {
        for (int i = 0; i < vec.size(); ++i ) {
            if (target == vec[i]) return true;
        }
        return false;
    }
};

int main() {
    Solution solu;
    vector<int> vec = {2,5,6,0,0,1,2};
    if (solu.search(vec,0))
        cout << "true" << endl;
    else cout << "false" << endl;

    return 0;
}
