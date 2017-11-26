class Solution {
public:
    //剑指offer第40题
    vector<int> singleNumber(vector<int>& nums) {
        int num1 = 0;
        int num2 = 0;
        int resultExclusiveOR = 0;
        vector<int> res;

        int length = nums.size();
        for (int i = 0; i < length; ++i){
            resultExclusiveOR ^= nums[i];
        }

        int numBit = First1(resultExclusiveOR);     //找到resultExclusiveOR的第几位为1

        //将第First1位为1的与num1异或，将第First1位为0的与num2异或；
        for(int i = 0; i < length; ++i){
            if (is1(nums[i], numBit))
                num1 ^= nums[i];
            else
                num2 ^= nums[i];
        }

        res.push_back(num1);
        res.push_back(num2);

        return res;

    }
private:
    //找到第几位首先为1（从右数）
    int First1(int num){
        int res = 0;
        while ((num & 1) != 1){
            num = num >> 1;
            ++res;
        }
        return res;
    }

    //判断第k位是不是1
    bool is1(int num, int k){
        int One = 1;
        for (int i = 0; i < k; ++i){
            One = One << 1;
        }

        if (num & One)
            return true;
        else
            return false;
    }
};
