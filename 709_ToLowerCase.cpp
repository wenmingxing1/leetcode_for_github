#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string toLowerCase(string str) {
        string res;

        for (auto ch : str) {
            if (ch >= 'A' && ch <= 'Z')
                res.push_back(ch+32);
            else
                res.push_back(ch);
        }
        return res;
    }
};

int main() {
    Solution solu;
    string test1 = "Hello";

    cout << solu.toLowerCase(test1) << endl;

    return 0;
}
