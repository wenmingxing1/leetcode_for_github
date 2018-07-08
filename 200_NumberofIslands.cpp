#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        int row = grid.size();  if (row == 0) return 0;
        int col = grid[0].size(); if (col == 0) return 0;
        vector<vector<bool>> visited(row, vector<bool>(col, false));

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j]=='1' && visited[i][j]==false) {
                    append_visited(grid, i, j, visited);
                    ++res;
                }
            }
        }
        return res;
    }
private:
    void append_visited(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& visited) {
        if (i < 0 || i >= grid.size()) return;
        if (j < 0 || j >= grid[0].size())return;

        if (grid[i][j] != '1' || visited[i][j]) return; //不可缺少的递归结束条件

        visited[i][j] = true;

        append_visited(grid, i, j-1, visited);
        append_visited(grid, i, j+1, visited);
        append_visited(grid, i-1, j, visited);
        append_visited(grid, i+1, j, visited);
    }
};

int main() {
    Solution solu;
    vector<vector<char>> test1 = { {'1', '1', '0', '0', '0' }, { '1', '1', '0', '0', '0' },
                                    { '0', '0', '1', '0', '0' }, { '0', '0', '0', '1', '1' } };
    cout << solu.numIslands(test1) << endl;

    return 0;
}
