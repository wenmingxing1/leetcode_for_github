class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0;
        int index = s.size()-1;

        //先取出最后的空格
        while (index >= 0 && s[index]==' ')
            --index;

        for (int i = index; i >= 0; --i) {
            if (s[i] != ' ') ++res;
            else break;
        }
        return res;
    }
};
