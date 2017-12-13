//��ָoffer20��
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

        //ά���ĸ�������ȷ�������߽�
        int rowBegin = 0;
        int rowEnd = row - 1;
        int colBegin = 0;
        int colEnd = col - 1;

        while (rowBegin <= rowEnd && colBegin <= colEnd){
            for (int i = colBegin; i <= colEnd; ++i){
                res.push_back(matrix[rowBegin][i]);     //����rowBegin==0
            }
            ++rowBegin;     //ȥ����0�У�����rowBegin==1

            for (int i = rowBegin; i <= rowEnd; ++i){
                res.push_back(matrix[i][colEnd]);   //����colEndΪ���һ��
            }
            --colEnd;   //ȥ�����һ��

            if (rowEnd >= rowBegin){    //��ֹ�ظ�������ֻ��һ��
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
