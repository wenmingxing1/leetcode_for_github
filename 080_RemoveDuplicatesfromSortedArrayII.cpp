#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int length = nums.size();
        if (length <= 2) return length;

        int index = 2;
        for (int i = 2; i < length; ++i) {
            //刚开始index与i都位于2的位置
            //如果i处与前两个相等，则i自己向前走
            //走到不等的地方，则将i的值赋给index处，i与index一起向前走
            //最后的结果是index走到了新数组的末尾，i走到原数组的末尾
            if (nums[index-2] != nums[i]) {
                nums[index] = nums[i];
                ++index;
            }
        }
        return index;
    }
};

int main() {
    Solution solu;
    vector<int> test1 = {1,1,1,2,2,3};
    vector<int> test2 = {0,0,1,1,1,1,2,3,3};

    cout << solu.removeDuplicates(test1) << endl << solu.removeDuplicates(test2) << endl;

    return 0;
}
