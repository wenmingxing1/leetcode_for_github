#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string str;
        vector<string> res;
        generateParenthesisCore(n, n, str, res);

        return res;
    }
private:
    void generateParenthesisCore(int left, int right, string str, vector<string>& res) {
        if (left == 0 && right == 0) {
            res.push_back(str);
            return;
        }

        //�����Ÿ�������0����Է�������
        if (left > 0) {
            generateParenthesisCore(left-1, right, str+'(', res);
        }

        //�����Ÿ������������Ÿ���������Է�������
        if (right > left) {
            generateParenthesisCore(left, right-1, str+')', res);
        }
    }
};

int main() {
    Solution solu;
    vector<string> res = solu.generateParenthesis(3);

    for (auto s : res)
        cout << s << endl;

    return 0;
}
