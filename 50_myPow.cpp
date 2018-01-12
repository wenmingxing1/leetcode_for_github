//剑指offer11题原题，但是LeetCode上需要处理int的边界问题
class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;
        if (n < 0) {
            if (n == INT_MIN) return 1/(Pow_nor(x, INT_MAX)*x);     //这是为了处理这种特殊情况，INT_MIN=-2147483648；INT_MAX=2147483647
            else return 1/Pow_nor(x, -n);
        }
        else
            return Pow_nor(x, n);

        return res;

    }

private:
    //判断两个double是否相等
    bool equal(double i, double j) {
        if ( (i - j <= 0.0000001) && (i - j >= -0.0000001) )
            return true;
        else
            return false;
    }

    //假定n为正的一般Pow
    double Pow_nor(double x, int n) {
        if (n == 0)     //两个递归结束条件
            return 1.0;
        if (n == 1)
            return x;

        double result = Pow_nor(x, n>>1);   //递归调用Pow_nor
        result *= result;
        if (n & 0x01)
            result *= x;

        return result;
    }

};
