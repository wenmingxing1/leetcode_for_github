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
            //�������������Ҫ����res��һ���������µĲ��ظ�Ԫ�أ�һ����left�Ѿ�����������Ԫ�ص�������λ��
            //����������Խ��
            if (myMap[s[i]]==0 || myMap[s[i]] < left) {
                res = res > (i-left+1) ? res : (i-left+1);
            }
            else {
                left = myMap[s[i]];
            }
            myMap[s[i]] = i+1;  //��¼Ϊ�����ֵ�λ�ã��Ը���left
        }
        return res;
    }
};

/*����set���*/
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
