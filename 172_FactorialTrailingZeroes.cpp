/*ע��25����ʵ����������5*/
#include<iostream>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        //2�ĸ����϶��Ƕ���5�ĸ����ģ�����ֱ�Ӽ���5�ĸ������ٽ�25����������ǽ�ȥ����
        while (n) {
            count += n/5;   //5�ĸ�����
            n /= 5;     //25�������
        }
        return count;
    }
};

int main() {
    int n;
    cin >> n;
    Solution s;
    cout << s.trailingZeroes(n) << endl;

    return 0;
}
