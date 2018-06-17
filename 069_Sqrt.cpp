#include<iostream>
#include<math.h>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        int left = 1;
        int right = x;
        int mid = left;
        while (left <= right) {
            mid = left + (right - left) / 2;
            //����ֱ����mid*mid���ܻᳬ��int�ķ�Χ�����Բ�����һ�ֱ�����ʽ
            if (mid < x/mid) {
                if ((mid+1) > x/(mid+1)) return mid;
                else left = mid + 1;
            }
            else if (mid == x/mid) return mid;
            else right = mid - 1;
        }
        return 0;

    }
};

int main() {
    Solution solu;
    int test1 = 4;
    int test2 = 95000;

    cout << solu.mySqrt(test1) << " " << sqrt(test1) << endl;
    cout << solu.mySqrt(test2) << " " << sqrt(test2) << endl;
}
