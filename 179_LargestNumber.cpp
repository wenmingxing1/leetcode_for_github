class Solution {
public:
    //剑指offer第33题为求最小，此题为求最大
    static bool compare(int i, int j){
        string A = "";
        string B = "";

        A += to_string(i);
        A += to_string(j);

        B += to_string(j);
        B += to_string(i);

        return A > B;
    }
    string largestNumber(vector<int>& nums) {
        string res = "";
        sort(nums.begin(), nums.end(), compare);
        if (nums[0] == 0)   //如果数组中全都是0
            return "0";
        for (int i = 0; i < nums.size(); ++i){
            res += to_string(nums[i]);
        }

        return res;
    }
};
