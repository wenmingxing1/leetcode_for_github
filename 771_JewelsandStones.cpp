#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int res = 0;

        vector<int> Jhash(256, 0);

        for (auto ch : J) {
            ++Jhash[ch];
        }

        for (auto ch : S) {
            if (Jhash[ch])
                ++res;
        }
        return res;
    }
};


int main() {
    Solution solu;
    string J = "aA";
    string S = "aAAbbbb";

    cout << solu.numJewelsInStones(J, S) << endl;

    return 0;
}
