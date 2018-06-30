#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();

        if (row < 1 || col < 1 || word.size() == 0) return false;

        //记录是否被访问
        vector<vector<bool>> visited(row, vector<bool>(col, false));

        int wordIndex = 0;  //记录word位置

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (existCore(board, row, col, i, j, word, wordIndex, visited))
                    return true;
            }
        }

        return false;
    }
private:
    bool existCore(vector<vector<char>>& board, int row, int col,
                   int rowIndex, int colIndex, string& word, int& wordIndex, vector<vector<bool>>& visited) {
        //递归结束条件
        if (word[wordIndex] == '\0') return true;

        bool found = false;


        if (rowIndex >= 0 && rowIndex < row && colIndex >= 0 && colIndex < col
            && board[rowIndex][colIndex] == word[wordIndex] && !visited[rowIndex][colIndex]) {

            ++wordIndex;
            visited[rowIndex][colIndex] = true;

            found = existCore(board, row, col, rowIndex-1, colIndex, word, wordIndex, visited)
                    || existCore(board, row, col, rowIndex+1, colIndex, word, wordIndex, visited)
                    || existCore(board, row, col, rowIndex, colIndex-1, word, wordIndex, visited)
                    || existCore(board, row, col, rowIndex, colIndex+1, word, wordIndex, visited);

            if (!found) {
                --wordIndex;
                visited[rowIndex][colIndex] = false;
            }
        }

        return found;
    }
};

int main() {
    Solution solu;
    vector<vector<char>> board = { {'A', 'B', 'C', 'E' }, {'S', 'F', 'C', 'S' }, { 'A', 'D', 'E', 'E' } };
    cout << solu.exist(board, "ABCCED") << endl;
    cout << solu.exist(board, "SEE") << endl;
    cout << solu.exist(board, "ABCB") << endl;

    return 0;
}
