//先对每一行进行判断（这里是顺序判断），在对对应的行进行二分查找；
//也可以对整个矩阵当做一个顺序数组直接二分查找；

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty())
            return false;

        int m = matrix.size();
        int n = matrix[0].size();
        bool res = false;
        int row = 0;
        int col = n - 1;

        while (row < m && col >= 0) {
            if (matrix[row][col] == target)     //找到指定值
                return true;
            //找到对应的行
            else if (matrix[row][col] > target) {
                return searchVector(matrix[row], target);
            }
            //去除行
            else if (matrix[row][col] < target) {
                ++row;
            }
        }

        return res;

    }
private:
    //二分查找一个vector
    bool searchVector(vector<int> vec, int target) {
        int left = 0;
        int right = vec.size() - 1;
        int middle = left + (right - left) / 2;
        bool res = false;
        while (left <= right) {
            int middle = left + (right - left) / 2;
            if (vec[middle] == target) {
                return true;
            }
            else if (vec[middle] > target) {
                right = middle-1;
            }
            else if (vec[middle] < target) {
                left = middle+1;
            }
        }
        return res;
    }

};
