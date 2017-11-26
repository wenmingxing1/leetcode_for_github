#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int length = nums.size();
        int res = 0;
        for (int i = 0; i < 32; ++i){
            int count = 0;
            int mask = 1 << i;      //�ֱ�Ϊ1,10,100��... Ŀ����Ϊ�˼���ڼ�λ

            for (int j = 0; j < length; ++j){   //�����iλ��1�ĸ���
                if ((nums[j] & mask) != 0)      //ע��λ�����������ȼ��ܵ͵�����
                    ++count;
            }

            if (count % 3)  //ģ3�������1����֤��single number��λΪ1
                res = res | mask;
        }
        return res;
    }
};


int main()
{
    vector<int> nums = {1};
    Solution solu;
    cout << solu.singleNumber(nums) << endl;

    return 0;
}
