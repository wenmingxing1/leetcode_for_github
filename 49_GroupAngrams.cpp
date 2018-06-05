#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mymap;

        for (auto s : strs) {
            vector<int> count(26,0);
            for (auto ch : s) ++count[ch-'a'];

            //��countת��Ϊstring
            string temp;
            for (auto i : count) temp += to_string(i);

            mymap[temp].push_back(s);   //ÿ����Ӧ��ת��Ϊstring���ַ�����ѹ�뵽��ͬ��mapλ����
        }

        for (auto a : mymap) {
            res.push_back(a.second);
        }

        return res;
    }
};
