/*
class Solution {
public:
    //����set���жϣ�set�ĵײ�ʵ���Ǻ����
    bool containsDuplicate(vector<int>& nums) {
        set<int> res(nums.begin(), nums.end());
        return nums.size() > res.size();
    }
};
*/

class Solution {
    public:
    //ֱ�����������жϣ���ı����飬�ռ临�Ӷ�ΪO(1)
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); ++i){
            if (nums[i] == nums[i-1])
                return true;
        }
        return false;
    }
};
