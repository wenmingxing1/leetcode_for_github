//剑指offer20题
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty()) return res;
        int row = matrix.size();
        int col = matrix[0].size();

        //维护四个变量以确定遍历边界
        int rowBegin = 0;
        int rowEnd = row - 1;
        int colBegin = 0;
        int colEnd = col - 1;

        while (rowBegin <= rowEnd && colBegin <= colEnd){
            for (int i = colBegin; i <= colEnd; ++i){
                res.push_back(matrix[rowBegin][i]);     //现在rowBegin==0
            }
            ++rowBegin;     //去除第0行，现在rowBegin==1

            for (int i = rowBegin; i <= rowEnd; ++i){
                res.push_back(matrix[i][colEnd]);   //现在colEnd为最后一列
            }
            --colEnd;   //去除最后一列

            if (rowEnd >= rowBegin){    //防止重复，例如只有一行
                for (int i = colEnd; i >= colBegin; --i){
                    res.push_back(matrix[rowEnd][i]);
                }
            }
            --rowEnd;

            if (colEnd >= colBegin){
                for (int i = rowEnd; i >= rowBegin; --i){
                    res.push_back(matrix[i][colBegin]);
                }
            }
            ++colBegin;
        }
        return res;
    }
};

int main()
{
    Solution solu;
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> res;
    res = solu.spiralOrder(matrix);

    for (int i = 0; i < res.size(); ++i){
        cout << res[i] << ",";
    }

    return 0;
}
