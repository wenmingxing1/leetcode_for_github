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

            //将count转化为string
            string temp;
            for (auto i : count) temp += to_string(i);

            mymap[temp].push_back(s);   //每个对应于转化为string的字符串都压入到相同的map位置中
        }

        for (auto a : mymap) {
            res.push_back(a.second);
        }

        return res;
    }
};
