class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res;
        for (int i = 0; i <= num; ++i) {
            res.push_back(numOf1(i));
        }
        return res;
    }

private:
    //判断一个整数的二进制有多少个1
    int numOf1(int n) {
        int count = 0;
        while (n) {
            ++count;
            n = n & (n - 1);    //n与n-1与会让n的最右边一个1变为0
        }
        return count;
    }
};
