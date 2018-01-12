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
    //�ж�һ�������Ķ������ж��ٸ�1
    int numOf1(int n) {
        int count = 0;
        while (n) {
            ++count;
            n = n & (n - 1);    //n��n-1�����n�����ұ�һ��1��Ϊ0
        }
        return count;
    }
};
