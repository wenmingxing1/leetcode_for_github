#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    //类似于剑指offer55：字符流中第一个不重复的字符，用hash方法
    int firstUniqChar(string s) {
        int length = s.size();
        vector<int> hash(256,0);   //刚开始都是0次
        for (int i = 0; i < length; ++i){
            hash[s[i]]++;
        }

        for (int i = 0; i < length; ++i){
            if (hash[s[i]] == 1){
                return i;
            }
        }
        return -1;
    }
};

int main()
{
    string s = "loveleetcode";
    Solution solu;
    int res = solu.firstUniqChar(s);

    cout << res << endl;

    return 0;
}
