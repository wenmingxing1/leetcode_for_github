#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string res;
        while(n) {
            char temp;
            if (n%26 == 0) {
                temp = 'Z';
                n -= 26;
            }
            else {
                temp = n%26+64;
                n = n-n%26;
            }
            n = n/26;
            res.push_back(temp);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution solu;
    cout << solu.convertToTitle(52) << endl;

    return 0;
}
