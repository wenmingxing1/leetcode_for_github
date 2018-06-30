#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    bool canJump(vector<int>& nums){
        int length = nums.size();
        int reach = 0;  //¼ÇÂ¼ÄÜµ½´ïµÄ×îÔ¶Î»ÖÃ
        for (int i = 0; i < length-1 && i <= reach; ++i){
            reach = max(i+nums[i], reach);
        }
        return reach >= length-1;
    }
};

int main()
{
    vector<int> num1 = {2,3,1,1,4};
    vector<int> num2 = {3,2,1,0,4};
    Solution solu;
    cout << solu.canJump(num1) << endl;
    cout << solu.canJump(num2) << endl;

    return 0;
}
