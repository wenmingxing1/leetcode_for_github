//�ȶ�ÿһ�н����жϣ�������˳���жϣ����ڶԶ�Ӧ���н��ж��ֲ��ң�
//Ҳ���Զ�����������һ��˳������ֱ�Ӷ��ֲ��ң�

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
            if (matrix[row][col] == target)     //�ҵ�ָ��ֵ
                return true;
            //�ҵ���Ӧ����
            else if (matrix[row][col] > target) {
                return searchVector(matrix[row], target);
            }
            //ȥ����
            else if (matrix[row][col] < target) {
                ++row;
            }
        }

        return res;

    }
private:
    //���ֲ���һ��vector
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
