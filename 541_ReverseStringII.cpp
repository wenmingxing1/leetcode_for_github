#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        int length = s.size();
        if (length < k){
            Reverse(s, 0, length-1);
        }
        else{
            for (int i = 0; i <= (length/(2*k)); ++i){
                if (2*i*k+k-1 <= length-1)  //ÅÐ¶ÏÊÇ·ñÔ½½ç
                    Reverse(s, 2*i*k, 2*i*k+k-1);
                else
                    Reverse(s, 2*i*k, length-1);
            }
        }

        return s;
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
};

int main()
{
    string str = "yzqyljrnigxvdtneasepfahmtyhlohwxmkqcdfehybknvdmfrfvtbsovjbdhevlfxpdaovjgunjqlimjkfnqcqnajmebeddqsgl";
    Solution solu;
    cout << solu.reverseStr(str, 39) << endl;

    return 0;
}
