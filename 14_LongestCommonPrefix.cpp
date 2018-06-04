#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        int row = strs.size();
        if (row == 0) return res;

        int col = strs[0].size();

        for (int i = 0; i < row; ++i) {
            if (strs[i].size() < col)
                col = strs[i].size();
        }

        for (int i = 0; i < col; ++i) {
            char temp = strs[0][i];
            for (int j = 1; j < row; ++j) {
                if (strs[j][i] != temp)
                    return res;
            }
            res.push_back(temp);
        }
        return res;
    }
};

int main() {
    Solution solu;
    vector<string> vec = { "flower","flow","flight" };

    string res = solu.longestCommonPrefix(vec);

    cout << res << endl;

    return 0;
}
