//��ָoffer28�⣬�ַ�������
class Solution {
public:
    //vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        permuteCore(nums, 0, res);
        return res;
    }
private:
    void permuteCore(vector<int>& nums, int begin, vector<vector<int>>& res){
        if (begin == nums.size()){  //����һ�ֵݹ��е�begin+1==size��ʱ��ѹ��nums
            res.push_back(nums);
            return;
        }
        else{
            for (int i = begin; i < nums.size(); ++i){
                swap(nums[begin], nums[i]);
                permuteCore(nums, begin+1, res);
                swap(nums[begin], nums[i]);
            }
        }
    }
};
