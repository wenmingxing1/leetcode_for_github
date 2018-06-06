#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.size() == 0) return res;

        vector<string> dict = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        string out;
        letterCombinationsCore(digits, dict, 0, out, res);

        return res;
    }
private:
    //level用来记录第几个数字
    void letterCombinationsCore(string digits, vector<string>& dict, int level, string& out, vector<string>& res) {
        if (level == digits.size()) {
            res.push_back(out);
            return;
        }

        string temp = dict[digits[level]-'2'];

        for (int i = 0; i < temp.size(); ++i) {
            out.push_back(temp[i]);
            letterCombinationsCore(digits, dict, level+1, out, res);
            out.pop_back();
        }
    }
};

int main() {
    Solution solu;
    string dig = "23";
    vector<string> res = solu.letterCombinations(dig);

    for (auto s : res) {
        cout << s << endl;
    }

    return 0;
}
