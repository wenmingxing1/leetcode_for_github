#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int index1 = 0;
        int index2 = 0;
        int length1 = haystack.size();
        int length2 = needle.size();
        if (length2 == 0) return 0;

        //index1不必遍历到最后
        while (index1 < (length1-length2+1) && index2 < length2) {
            if (haystack[index1] == needle[index2]) {
                int res = index1;
                while (haystack[index1] == needle[index2] && index1<length1 && index2<length2) {
                    ++index1; ++index2;
                }

                if(index2 == length2) return res;
                else {
                    index1 = res + 1; index2 = 0;
                }
            }

            else ++index1;
        }
        return -1;
    }

};

int main() {
    Solution solu;
    string haystack = "a";
    string needle = "a";

    cout << solu.strStr(haystack, needle) << endl;

    return 0;
}
