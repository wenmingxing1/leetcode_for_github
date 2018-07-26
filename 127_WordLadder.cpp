#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
#include<queue>

using namespace std;

//这是一道典型的BFS题目
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

                //变换单词的每一位
                for (int i = 0; i < length; ++i) {
                    char ch = w[i];     //先记录
                    //尝试变换
                    for (int j = 'a'; j <= 'z'; ++j) {
                        w[i] = j;
                        if (w == endWord) return level+1;    //满足条件

                        //如果dict中没有变换后的单词，则尝试下一个字母的转变
                        if (!dict.count(w)) continue;

                        //只能使用一次
                        dict.erase(w);

                        //BFS做法
                        q.push(w);
                    }
                    //再转换回去，才能进行下一位的尝试
                    w[i] = ch;
                }
            }

        }
        return 0;
    }
};
