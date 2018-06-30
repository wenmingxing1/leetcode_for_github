#include<iostream>
#include<vector>

using namespace std;

//以一个奇怪的数占位-12345
class Solution1 {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (matrix[i][j] == 0) {
                    setZeroesCore(matrix, i, j, row, col);
                }
            }
        }

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (matrix[i][j] == -12345)
                    matrix[i][j] = 0;
            }
        }
    }
private:
    void setZeroesCore(vector<vector<int>>& matrix, int a, int b, int row, int col) {
        for (int i = 0; i < col; ++i) {
            if (matrix[a][i] != 0) matrix[a][i] = -12345;
        }

        for (int i = 0; i < row; ++i) {
            if (matrix[i][b] != 0) matrix[i][b] = -12345;
        }
    }
};

//使用第一行和第一列记录是否需要变为0，另取两个变量分别看第一行和第一列的情况
class Solution2 {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        bool firstRow = false;
        bool firstCol = false;

        //先判断第一行和第一列，从而更新firstRow和firstCol
        for (int i = 0; i < col; ++i) {
            if (matrix[0][i] == 0) {
                firstRow = true;
                break;
            }
        }
        for (int i = 0; i < row; ++i) {
            if (matrix[i][0] == 0) {
                firstCol = true;
                break;
            }
        }


        //判断其他行与列，以更新第一行和第一列中的bool值
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;   //如果本行需要赋0，则将其标记为0
                    matrix[0][j] = 0;
                }
            }
        }


        //根据上述bool值，进行赋0操作
        //先不对第一行和第一列进行操作，以免覆盖
        for (int i = 1; i < col; ++i) {
            if (matrix[0][i] == 0) {    //则第i列全部赋0
                for (int j = 1; j < row; ++j)
                    matrix[j][i] = 0;
            }
        }

        for (int i = 1; i < row; ++i) {
            if (matrix[i][0] == 0) {    //则第i行全部赋0
                for (int j = 1; j < col; ++j)
                    matrix[i][j] = 0;
            }
        }

        if (firstRow == true) {
            for (int i = 0; i < col; ++i)
                matrix[0][i] = 0;
        }

        if (firstCol == true) {
            for (int i = 0; i < row; ++i)
                matrix[i][0] = 0;
        }
    }
};

int main() {
    Solution1 solu1;
    Solution2 solu2;
    vector<vector<int>> vec1{ {0,1,2,0}, {3,4,5,2}, {1,3,1,5} };
    vector<vector<int>> vec2{ {1,1,1}, {1,0,1}, {1,1,1} };
    solu2.setZeroes(vec2);

    for (auto v : vec2) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}
