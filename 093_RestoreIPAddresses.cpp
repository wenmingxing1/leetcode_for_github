#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if (s.size()>12 || s.size()<4) return res;
        restore(s, 4, "", res);
        return res;
    }
private:
    void restore(string s, int k, string out, vector<string>& res) {
        //递归结束条件，当需要段数为0，并且s已经为空的时候
        if (k == 0 && s.empty()) {
            res.push_back(out);
        }

        else {
            //每一段可以是1位，2位，或3位
            for (int i = 1; i <= 3; ++i) {
                if (s.size() >= i && isVaild(s.substr(0,i))) {
                    //只还需要一段的时候，末尾不需要加"."
                    if (k == 1) restore(s.substr(i), k-1, out+s.substr(0,i), res);
                    else restore(s.substr(i), k-1, out+s.substr(0,i) + ".", res);
                }
            }
        }
    }

    //判断一段是否有效
    bool isVaild(string s) {
        if (s.empty() || s.size() > 3 || (s.size()>1 && s[0]=='0')) return false;
        int res = stoi(s);
        return res <= 255 && res >= 0;
    }
};

