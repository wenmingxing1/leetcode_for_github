#include<iostream>
#include<string>
#include<unordered_set>
#include<vector>

using namespace std;

class Solution1 {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> myMap(256, 0);
        int left = 0;
        int res = 0;
        int length = s.size();
        if (length == 0) return 0;
        for (int i = 0; i < length; ++i) {
            //在两种情况下需要更新res，一种是来了新的不重复元素，一种是left已经超过了新来元素的最后出现位置
            //即滑动窗口越过
            if (myMap[s[i]]==0 || myMap[s[i]] < left) {
                res = res > (i-left+1) ? res : (i-left+1);
            }
            else {
                left = myMap[s[i]];
            }
            myMap[s[i]] = i+1;  //记录为最后出现的位置，以更新left
        }
        return res;
    }
};

/*利用set完成*/
class Solution2 {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int start = 0;
        int index = 0;
        int length = s.size();
        if (length == 0) return 0;
        unordered_set<char> mySet;
        while (index < length) {
            if (!mySet.count(s[index])) {
                mySet.insert(s[index++]);
                res = res > mySet.size() ? res : mySet.size();
            }
            else {
                mySet.erase(s[start++]);
            }
        }
        return res;
    }
};

int main() {
    Solution1 solu1;
    Solution2 solu2;
    string test1 = "abcabcbb";
    cout << solu1.lengthOfLongestSubstring(test1) << endl;
    cout << solu2.lengthOfLongestSubstring(test1) << endl;

    return 0;
}
