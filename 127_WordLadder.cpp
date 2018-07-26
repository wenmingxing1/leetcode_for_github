#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
#include<queue>

using namespace std;

//����һ�����͵�BFS��Ŀ
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int length = beginWord.size();
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return 0;
        queue<string> q;
        q.push(beginWord);

        int level = 0;

        while (!q.empty()) {
            ++level;
            for (int size = q.size(); size > 0; --size) {
                string w = q.front();
                q.pop();

                //�任���ʵ�ÿһλ
                for (int i = 0; i < length; ++i) {
                    char ch = w[i];     //�ȼ�¼
                    //���Ա任
                    for (int j = 'a'; j <= 'z'; ++j) {
                        w[i] = j;
                        if (w == endWord) return level+1;    //��������

                        //���dict��û�б任��ĵ��ʣ�������һ����ĸ��ת��
                        if (!dict.count(w)) continue;

                        //ֻ��ʹ��һ��
                        dict.erase(w);

                        //BFS����
                        q.push(w);
                    }
                    //��ת����ȥ�����ܽ�����һλ�ĳ���
                    w[i] = ch;
                }
            }

        }
        return 0;
    }
};
