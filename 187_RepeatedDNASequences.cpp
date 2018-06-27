#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution1 {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int length = s.size();
        if (length <= 10) return vector<string>();

        unordered_set<string> myHash;
        unordered_set<string> tempRes;

        for (int i = 0; i < length - 9; ++i) {
            string str = s.substr(i,10);
            if (myHash.count(str)) tempRes.insert(str);
            else myHash.insert(str);
        }
        return vector<string>(tempRes.begin(), tempRes.end());
    }
};

//优化内存空间，可以以bit位存储到set
// A->00, C->01, G->10, T->11
// 通过这个映射，可以将存储子串转化为了存储一个int型
class Solution2 {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int length = s.size();
        if (length <= 10) return vector<string>();

        unordered_map<char, int> myHash{ {'A', 0}, {'C', 1}, {'G', 2}, {'T', 3} };
        unordered_set<int> temp;
        unordered_set<string> tempRes;

        int cur = 0; int i = 0;

        //这里是为了确定到第10个字符流形成一个cur
        while (i < 9) {
            cur = (cur << 2) | myHash[s[i]];    //追加后面的字符bit
            ++i;
        }

        while (i < length) {
            //0x3ffff的作用是取出20位，但是因为要右移2位，所以只需使用18位
            //这里也是因为等号右边的cur此时是18位
            cur = ((cur & 0x3ffff) << 2 ) | myHash[s[i]];
            ++i;
            if (temp.count(cur)) tempRes.insert(s.substr(i-10,10));
            else temp.insert(cur);
        }
        vector<string> res(tempRes.begin(), tempRes.end());
        return res;
    }
};

int main() {
    string input = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    Solution1 solu1;
    vector<string> res1 = solu1.findRepeatedDnaSequences(input);

    for (auto s : res1) {
        cout << s << endl;
    }

    cout << endl << endl;

    Solution2 solu2;
    vector<string> res2 = solu2.findRepeatedDnaSequences(input);
    for (auto s : res2) cout << s << endl;

    return 0;
}
