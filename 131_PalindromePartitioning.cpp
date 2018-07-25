#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        int length = s.size();
        if (length == 0) return vector<vector<string>>();

        vector<vector<string>> res;
        vector<string> temp;

        partitionCore(s, 0, temp, res);

        return res;
    }
private:
    void partitionCore(string s, int start, vector<string>& temp, vector<vector<string>>& res) {
        if (start == s.size()) {
            res.push_back(temp);
            return;
        }

        for (int i = start; i < s.size(); ++i) {
            if (isVaild(s, start, i)) {
                temp.push_back(s.substr(start, i-start+1));
                partitionCore(s, i+1, temp, res);

                temp.pop_back();
            }
        }
    }

    bool isVaild(string s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            ++left;
            --right;
        }
        return true;
    }
};

int main() {
    Solution solu;
    string str = "aabb";
    vector<vector<string>> res = solu.partition(str);

    for (auto v : res) {
        for (auto s : v) {
            cout << s << " ";
        }
        cout << endl;
    }
    return 0;
}
