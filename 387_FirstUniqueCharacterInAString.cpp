#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    //�����ڽ�ָoffer55���ַ����е�һ�����ظ����ַ�����hash����
    int firstUniqChar(string s) {
        int length = s.size();
        vector<int> hash(256,0);   //�տ�ʼ����0��
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
