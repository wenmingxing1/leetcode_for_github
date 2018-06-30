class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int index = m + n - 1;  //关键
        while (i >= 0 && j >= 0){   //在两个数组都存在元素的情况下，经过比较
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
        while (i >= 0){     //nums2为空
            nums1[index] = nums1[i];
            i--;
            index--;
        }
        while (j >= 0){     //nums1为空
            nums1[index] = nums2[j];
            j--;
            index--;
        }
    }
};
