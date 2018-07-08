#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        int row = grid.size(); if (row == 0) return 0;
        int col = grid[0].size(); if (col == 0) return 0;

        vector<vector<bool>> visited(row, vector<bool>(col, false));

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {

                if (grid[i][j] == 1 && visited[i][j] == false) {
                    int count = 0;
                    append_visited(grid, i, j, visited, count);
                    res = res>count?res:count;
                }
            }
        }
        return res;
    }
private:
    void append_visited(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited, int& count) {
        if (i < 0 || i >= grid.size()) return;
        if (j < 0 || j >= grid[0].size()) return;

        if (grid[i][j] != 1 || visited[i][j] == true) return;

        visited[i][j] = true;
        ++count;

        append_visited(grid, i-1, j, visited, count);
        append_visited(grid, i+1, j, visited, count);
        append_visited(grid, i, j-1, visited, count);
        append_visited(grid, i, j+1, visited, count);

    }
};
