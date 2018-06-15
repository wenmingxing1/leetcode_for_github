#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

/*ʹ��map��Ϊӳ��*/
class Solution1 {
public:
    int titleToNumber(string s) {
        int res = 0;
        int length = s.size();
        if (length == 0) return 0;
        unordered_map<char, int> myMap;

        //��ʼ��hash
        for (int i = 'A'; i <= 'Z'; ++i) {
            myMap[i] = i-64;
        }

        int index = 0;
        while (index < length) {
            res = res*26+myMap[s[index]];
            ++index;
        }
        return res;
    }
};

//��ʵҲ����ֱ�ӽ���ת��
class Solution2 {
public:
    int titleToNumber(string s) {
        int res = 0;
        int length = s.size();
        if (length == 0) return 0;
        for (int i = 0; i < length; ++i) {
            res = (s[i]-64)+ res*26;
        }
        return res;
    }
};



int main() {
    Solution1 solu1;
    Solution2 solu2;
    string test1 = "C";
    string test2 = "ZY";
    string test3 = "KAA";

    cout << solu1.titleToNumber(test1) << "," << solu1.titleToNumber(test2) << "," << solu1.titleToNumber(test3) << endl;

    cout << solu2.titleToNumber(test1) << "," << solu2.titleToNumber(test2) << "," << solu2.titleToNumber(test3) << endl;

    return 0;
}
