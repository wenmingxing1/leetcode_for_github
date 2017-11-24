class Solution {
public:
    //剑指offer42题的一部分
    string reverseWords(string s) {
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
            else{
                ++end;
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
