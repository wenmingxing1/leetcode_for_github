#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = 0;    //��¼ǰ���ж��ٸ�val���Ծ������治���ʱ�����ǰ��ֵ����λ
        for (int i = 0; i < nums.size(); ++i){
            if (nums[i] == val){
                len++;
            }
            else{
                nums[i - len] = nums[i];
            }
        }
        return nums.size() - len;
    }
};

int main()
{
    vector<int> nums = {1,3,3,5,6,3,2,2,4,2,3,3,5};
    int k = 3;
    Solution solu;

    int result = solu.removeElement(nums, k);

    for (int i = 0; i < result; ++i)
    {
        cout << nums[i] << " ";
    }

    return 0;
}
