class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int middle = left;          //�����תΪ0�������������ѭ��������ֱ�ӷ���left��ֵ

        while (nums[left] >= nums[right]){
            if (right - left == 1){     //ѭ����������
                middle = right;
                break;
            }
            middle = left + (right - left) / 2;
            if (nums[right] == nums[left] && nums[left] == nums[middle]){       //�������ֵ��ȣ����޷��ж�middle����һ���֣�ֻ��˳�����
                return *min_element(nums.begin(), nums.end());
            }

            if (nums[middle] >= nums[left]){
                left = middle;
            }
            if (nums[middle] <= nums[right]){
                right = middle;
            }
        }
        return nums[middle];
    }
};
