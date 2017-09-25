//���ö��ֲ��ң����return low�����ַ�ʽ�ܽ������λ�����⡣
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high){
            int middle = low + (high - low) / 2;    //һ��Ҫʹ�����ַ�ʽ����Ϊ���ʹ��low+high���ܳ���int��Χ
            if (target > nums[middle]){
                low = middle + 1;
            }
            else{
                high = middle - 1;
            }
        }
        return low;
    }
};
