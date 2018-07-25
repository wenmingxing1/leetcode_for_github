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
        //�ݹ��������������Ҫ����Ϊ0������s�Ѿ�Ϊ�յ�ʱ��
        if (k == 0 && s.empty()) {
            res.push_back(out);
        }

        else {
            //ÿһ�ο�����1λ��2λ����3λ
            for (int i = 1; i <= 3; ++i) {
                if (s.size() >= i && isVaild(s.substr(0,i))) {
                    //ֻ����Ҫһ�ε�ʱ��ĩβ����Ҫ��"."
                    if (k == 1) restore(s.substr(i), k-1, out+s.substr(0,i), res);
                    else restore(s.substr(i), k-1, out+s.substr(0,i) + ".", res);
                }
            }
        }
    }

    //�ж�һ���Ƿ���Ч
    bool isVaild(string s) {
        if (s.empty() || s.size() > 3 || (s.size()>1 && s[0]=='0')) return false;
        int res = stoi(s);
        return res <= 255 && res >= 0;
    }
};

