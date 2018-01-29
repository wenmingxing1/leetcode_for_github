class Solution {
public:
    string reverseString(string s) {
        string res = s;
        int length = s.size();
        int left = 0;
        int right = length - 1;
        while (left < right) {
            swap(res[left], res[right]);
            ++left;
            --right;
        }

        return res;
    }
};
