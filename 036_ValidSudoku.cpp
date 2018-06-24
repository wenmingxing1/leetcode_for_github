#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
        if (row == 0 || col == 0) return false;

        vector<vector<bool>> rowFlag(row, vector<bool>(col, false));
        vector<vector<bool>> colFlag(row, vector<bool>(col, false));
        vector<vector<bool>> cellFlag(row, vector<bool>(col, false));

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (board[i][j] >= '1' && board[i][j] <= '9') {
                    int c = board[i][j] - '1';
                    //证明已经有过
                    if (rowFlag[i][c] || colFlag[c][j] || cellFlag[3*(i/3)+j/3][c]) return false;

                    rowFlag[i][c] = true;
                    colFlag[c][j] = true;
                    //这里面对于cell的索引求法非常巧妙，3*(i/3)+j/3表示的是第i行第j列的位置所属于的cell
                    cellFlag[3*(i/3)+j/3][c] = true;
                }
            }
        }
        return true;
    }
};
