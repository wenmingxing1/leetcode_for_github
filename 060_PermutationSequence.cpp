#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        string num = "123456789";
        vector<int> f(n,1);
        for (int i = 1; i < n; ++i) {
            f[i] = f[i-1] * i;
        }
        --k;

        for (int i = n; i >= 1; --i) {
            int j = k/f[i-1];
            k = k%f[i-1];
            res.push_back(num[j]);
            num.erase(j,1);
        }
        return res;
    }
};

int main() {
    Solution solu;
    cout << solu.getPermutation(3,3) << endl;

    return 0;
}
