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
            //�տ�ʼindex��i��λ��2��λ��
            //���i����ǰ������ȣ���i�Լ���ǰ��
            //�ߵ����ȵĵط�����i��ֵ����index����i��indexһ����ǰ��
            //���Ľ����index�ߵ����������ĩβ��i�ߵ�ԭ�����ĩβ
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
