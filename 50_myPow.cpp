//��ָoffer11��ԭ�⣬����LeetCode����Ҫ����int�ı߽�����
class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;
        if (n < 0) {
            if (n == INT_MIN) return 1/(Pow_nor(x, INT_MAX)*x);     //����Ϊ�˴����������������INT_MIN=-2147483648��INT_MAX=2147483647
            else return 1/Pow_nor(x, -n);
        }
        else
            return Pow_nor(x, n);

        return res;

    }

private:
    //�ж�����double�Ƿ����
    bool equal(double i, double j) {
        if ( (i - j <= 0.0000001) && (i - j >= -0.0000001) )
            return true;
        else
            return false;
    }

    //�ٶ�nΪ����һ��Pow
    double Pow_nor(double x, int n) {
        if (n == 0)     //�����ݹ��������
            return 1.0;
        if (n == 1)
            return x;

        double result = Pow_nor(x, n>>1);   //�ݹ����Pow_nor
        result *= result;
        if (n & 0x01)
            result *= x;

        return result;
    }

};
