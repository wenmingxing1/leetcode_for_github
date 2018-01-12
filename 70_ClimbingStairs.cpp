//剑指offer第9题，这其实是一个Fibonacci数列的应用，因为只能走1和2，所以climbStairs(n) = climbStairs(n-2) + climbStairs(n-1)
class Solution {
public:
    //递归产生Fibonacci数列，这样会超时
    /*
    int climbStairs(int n) {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        return climbStairs(n-2) + climbStairs(n-1);
    }
    */

    //vector存储Fibonacci数列，直接遍历得到下一个，避免深度递归
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

    //利用循环产生Fibonacci，不需要额外的空间
    int climbStairs(int n) {
        int result[2] = {1, 2};
        if (n <= 2)
            return result[n-1];
        int FibN = 0;
        int i = 1;
        int j = 2;
        for (int k = 3; k <= n; ++k) {  //相当于刷双指针滑动
            FibN = i+j;
            i = j;
            j = FibN;
        }
        return FibN;
    }
};
