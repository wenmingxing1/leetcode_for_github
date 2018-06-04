#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        bool res = false;
        if (s.size() <= 1) return true;

        int left = 0; int right = s.size()-1;

        while (left < s.size()) {
            if (!isAlph(s[left]) && !isNum(s[left]) ) ++left;
            else break;
        }

        while (right >= 0) {
            if (!isAlph(s[right]) && !isNum(s[right])) --right;
            else break;
        }

        while (left <= right) {
            while (!isAlph(s[left]) && !isNum(s[left]))
                ++left;
            while (!isAlph(s[right]) && !isNum(s[right]))
                --right;

            if (isEqu(s[left], s[right])) {
                ++left; --right;
            }
            else return false;
        }
        return true;
    }
private:
    bool isAlph(char ch) {
        if ( (ch >= 'a' && ch <= 'z') ||(ch >= 'A' && ch <= 'Z') )
            return true;
        else return false;
    }

    bool isNum(char ch) {
        if (ch >= '0' && ch <= '9') return true;
        else return false;
    }

    bool isEqu(char ch1, char ch2) {
        if (isAlph(ch1)&&isAlph(ch2)) {
            if (ch1 == ch2 || ch1 == ch2-32 || ch1 == ch2+32)
                return true;
            else return false;
        }
        else if (isNum(ch1) && isNum(ch2)) {
            if (ch1 == ch2) return true;
            else return false;
        }

        else return false;

    }
};

int main() {
    Solution solu;
    string str = "0P";

    cout << solu.isPalindrome(str) << endl;

    return 0;
}
