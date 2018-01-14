//½£Ö¸offerµÚ3Ìâ
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty())
            return false;
        bool res = false;
        int m = matrix.size();
        int n = matrix[0].size();

        int row = 0;
        int col = n - 1;
        while (row < m && col >= 0) {
            if (matrix[row][col] == target)
                return true;
            else if (matrix[row][col] > target) {
                --col;
            }
            else if (matrix[row][col] < target) {
                ++row;
            }
        }
        return res;
    }
};
