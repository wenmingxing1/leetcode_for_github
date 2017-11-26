class Solution {
public:
    //��ָoffer��40��
    vector<int> singleNumber(vector<int>& nums) {
        int num1 = 0;
        int num2 = 0;
        int resultExclusiveOR = 0;
        vector<int> res;

        int length = nums.size();
        for (int i = 0; i < length; ++i){
            resultExclusiveOR ^= nums[i];
        }

        int numBit = First1(resultExclusiveOR);     //�ҵ�resultExclusiveOR�ĵڼ�λΪ1

        //����First1λΪ1����num1��򣬽���First1λΪ0����num2���
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
    //�ҵ��ڼ�λ����Ϊ1����������
    int First1(int num){
        int res = 0;
        while ((num & 1) != 1){
            num = num >> 1;
            ++res;
        }
        return res;
    }

    //�жϵ�kλ�ǲ���1
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
