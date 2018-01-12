//��ָoffer��9�⣬����ʵ��һ��Fibonacci���е�Ӧ�ã���Ϊֻ����1��2������climbStairs(n) = climbStairs(n-2) + climbStairs(n-1)
class Solution {
public:
    //�ݹ����Fibonacci���У������ᳬʱ
    /*
    int climbStairs(int n) {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        return climbStairs(n-2) + climbStairs(n-1);
    }
    */

    //vector�洢Fibonacci���У�ֱ�ӱ����õ���һ����������ȵݹ�
    /*
    int climbStairs(int n) {
        vector<int> Fibonacci(n+1,0);
        Fibonacci[0] = 1;
        Fibonacci[1] = 1;
        for (int i = 2; i <= n; ++i) {
            Fibonacci[i] = Fibonacci[i-1] + Fibonacci[i-2];
        }

        return Fibonacci[n];
    }
    */

    //����ѭ������Fibonacci������Ҫ����Ŀռ�
    int climbStairs(int n) {
        int result[2] = {1, 2};
        if (n <= 2)
            return result[n-1];
        int FibN = 0;
        int i = 1;
        int j = 2;
        for (int k = 3; k <= n; ++k) {  //�൱��ˢ˫ָ�뻬��
            FibN = i+j;
            i = j;
            j = FibN;
        }
        return FibN;
    }
};
