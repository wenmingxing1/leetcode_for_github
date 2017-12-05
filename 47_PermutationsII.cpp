//��ָoffer28��
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        permuteUniqueCore(nums, 0, res);
        return res;
    }
private:
    void permuteUniqueCore(vector<int>& nums, int begin, vector<vector<int>>& res){
        if (begin == nums.size()){
            res.push_back(nums);
        }
        else{
            for (int i = begin; i < nums.size(); ++i){
                if (!duplicate(nums, begin, i)){
                    swap(nums[begin], nums[i]);
                    permuteUniqueCore(nums, begin+1, res);
                    swap(nums[begin], nums[i]);
                }
            }
        }
    }

    //�ж��Ƿ����ظ������begin��i���Ѿ�������i��ͬ��Ԫ�أ�����Ҫ����begin��iԪ���ˣ���Ϊ֮ǰ�Ѿ���������
    bool duplicate(vector<int>& nums, int begin, int end){
        for (int i = begin; i < end; ++i){
            if (nums[i] == nums[end])
                return true;
        }
        return false;
    }

};
