#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    //在有多余空格的情况下还是有问题
    void reverseWords(string &s) {
        int length = s.size();
        if (length == 0)
            return;

        trim(s);
        //cout << s << endl;

        Reverse(s, 0, length-1);
        int start = 0;
        int end = 0;
        while (s[start] != '\0'){
            if (s[start] == ' '){
                ++start;
                ++end;
            }
            if (s[end] == ' ' || s[end] == '\0'){
                Reverse(s, start, --end);
                start = ++end;
            }
            else {
                ++end;
            }
        }
    }
private:
    void Reverse(string& str, int start, int end){
        while (start < end){
            Swap(&str[start], &str[end]);
            ++start;
            --end;
        }
    }

    void Swap(char* i, char* j){
        char temp = *i;
        *i = *j;
        *j = temp;
    }

    //去除前后空格
    void trim(string& str){
        if (!str.empty()){
            str.erase(0,str.find_first_not_of(' '));
            str.erase(str.find_last_not_of(' ') + 1);
        }
    }
};

int main()
{
    string str = "the sky is blue";
    Solution solu;
    solu.reverseWords(str);
    cout << str << endl;

    return 0;
}
