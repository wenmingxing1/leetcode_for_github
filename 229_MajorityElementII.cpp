//剑指offer第29题的第二种做法思想
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int length = nums.size();
        int time1 = 0;
        int time2 = 0;
        int num1, num2;
        vector<int> res;
        for (int i = 0; i < length; ++i){
            if (num1 == nums[i])    //必须放在time1==0判断之前
                ++time1;
            else if (num2 == nums[i])
                ++time2;
            else if (time1 == 0){
                time1 = 1;
                num1 = nums[i];
            }
            else if (time2 == 0){
                time2 = 1;
                num2 = nums[i];
            }
            else{
                --time1;
                --time2;
            }
        }
        //现在的num1和num2是候选,即出现次数最多的两个数
        time1 = 0;
        time2 = 0;
        for (int i = 0; i < length; ++i){
            if (nums[i] == num1)
                ++time1;
            else if (nums[i] == num2)
                ++time2;
        }
        if (time1 > length/3) res.push_back(num1);
        if (time2 > length/3) res.push_back(num2);

        return res;
    }

};
