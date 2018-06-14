#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int length1 = version1.size();
        int length2 = version2.size();

        int index1 = 0;
        int index2 = 0;

        while (index1 < length1 || index2 < length2) {
            int version1Part = 0;
            int version2Part = 0;

            while (version1[index1] != '.' && index1 < length1) {
                version1Part = version1Part * 10 + (version1[index1]-'0');
                ++index1;
            }

            while (version2[index2] != '.' && index2 < length2) {
                version2Part = version2Part * 10 + (version2[index2]-'0');
                ++index2;
            }

            if (version1Part > version2Part) return 1;
            if (version1Part < version2Part) return -1;
            if (version1Part == version2Part) {
                ++index1;
                ++index2;
            }
        }
        return 0;
    }
};



int main() {
    vector<string> test1{"0.1", "1.1"};
    vector<string> test2{"1.0.1", "1"};
    vector<string> test3{"7.5.2.4", "7.5.3"};
    vector<string> test4{"1.1", "1"};

    Solution solu;
    cout << solu.compareVersion(test1[0], test1[1]) << endl;
    cout << solu.compareVersion(test2[0], test2[1]) << endl;
    cout << solu.compareVersion(test3[0], test3[1]) << endl;
    cout << solu.compareVersion(test4[0], test4[1]) << endl;

    return 0;
}
