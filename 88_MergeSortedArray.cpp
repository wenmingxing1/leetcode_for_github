class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int index = m + n - 1;  //�ؼ�
        while (i >= 0 && j >= 0){   //���������鶼����Ԫ�ص�����£������Ƚ�
            if (nums1[i] > nums2[j]){
                nums1[index] = nums1[i];
                i--;
                index--;
            }
            else{
                nums1[index] = nums2[j];
                j--;
                index--;
            }
        }
        while (i >= 0){     //nums2Ϊ��
            nums1[index] = nums1[i];
            i--;
            index--;
        }
        while (j >= 0){     //nums1Ϊ��
            nums1[index] = nums2[j];
            j--;
            index--;
        }
    }
};
