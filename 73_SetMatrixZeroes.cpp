#include<iostream>
#include<vector>

using namespace std;

//��һ����ֵ���ռλ-12345
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

//ʹ�õ�һ�к͵�һ�м�¼�Ƿ���Ҫ��Ϊ0����ȡ���������ֱ𿴵�һ�к͵�һ�е����
class Solution2 {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        bool firstRow = false;
        bool firstCol = false;

        //���жϵ�һ�к͵�һ�У��Ӷ�����firstRow��firstCol
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


        //�ж����������У��Ը��µ�һ�к͵�һ���е�boolֵ
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;   //���������Ҫ��0��������Ϊ0
                    matrix[0][j] = 0;
                }
            }
        }


        //��������boolֵ�����и�0����
        //�Ȳ��Ե�һ�к͵�һ�н��в��������⸲��
        for (int i = 1; i < col; ++i) {
            if (matrix[0][i] == 0) {    //���i��ȫ����0
                for (int j = 1; j < row; ++j)
                    matrix[j][i] = 0;
            }
        }

        for (int i = 1; i < row; ++i) {
            if (matrix[i][0] == 0) {    //���i��ȫ����0
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
