#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

//先排序，再对比
class Solution1 {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s==t;
    }
};

class Solution2 {
public:
    bool isAnagram(string s, string t) {
        vector<int> map1(26, 0);
        vector<int> map2(26, 0);
        int length1 = s.size();
        int length2 = t.size();

        if (length1 != length2) return false;

        for (int i = 0; i<length1; ++i) {
            map1[s[i]-'a']++;
            map2[t[i]-'a']++;
        }

        for (int i = 0; i < 26; ++i) {
            if (map1[i] != map2[i]) return false;
        }

        return true;
    }
};

int main() {
    string str1 = "anagram";
    string str2 = "nagaram";

    Solution1 solu1;
    Solution2 solu2;
    cout << solu1.isAnagram(str1, str2) << endl;
    cout << solu2.isAnagram(str1, str2) << endl;

    return 0;
}
