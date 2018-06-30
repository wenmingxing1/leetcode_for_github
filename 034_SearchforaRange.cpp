#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2,-1);

        int index = search(nums, target);
        if (index == -1)
            return res;

        int start = index;
        int end = index;

        while (nums[start] == target && start >= 0) --start;
        while (nums[end] == target && end < nums.size()) ++end;

        res[0] = start+1;
        res[1] = end-1;

        return res;
    }
private:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;
        int mid = 0;
        while (start <= end) {
            mid = start + (end - start) / 2;
            if (nums[mid] == target) return mid;

            else if (nums[mid] > target)
                end = mid - 1;
            else start = mid + 1;
        }
        return -1;
    }
};

int main() {
    Solution solu;
    vector<int> vec = {5,7,7,8,8,10};

    vector<int> res1 = solu.searchRange(vec, 8);

    for (auto i : res1) {
        cout << i << " ";
    }
    cout << endl;

    vector<int> res2 = solu.searchRange(vec,6);
    for(auto i : res2)
        cout << i << " ";

    return 0;
}
