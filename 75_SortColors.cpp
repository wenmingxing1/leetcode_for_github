#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    //利用计数排序的思想
    void sortColors(vector<int>& nums) {
        vector<int> Mymap(3,0);
        for (int i = 0; i < nums.size(); ++i) {
            ++Mymap[nums[i]];
        }

        for (int i = 0; i < Mymap[0]; ++i) {
            nums[i] = 0;
        }
        for (int i = Mymap[0]; i < Mymap[1]+Mymap[0]; ++i) {
            nums[i] = 1;
        }
        for (int i = Mymap[1]+Mymap[0]; i < Mymap[2]+Mymap[1]+Mymap[0]; ++i) {
            nums[i] = 2;
        }
    }
};

int main() {
    Solution solu;
    vector<int> test = {2,0,2,1,1,0};
    solu.sortColors(test);

    for (auto i : test)
        cout << i << " ";

    return 0;
}
