#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr);
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int length = nums.size();
        if (length == 0) return nullptr;
        int start = 0;
        int end = length-1;

        TreeNode* root = sortedArrayToBSTCore(nums, start, end);
        return root;
    }
private:
    TreeNode* sortedArrayToBSTCore(vector<int>& nums, int start, int end) {
        if (start > end) return nullptr;

        int mid = start + (end - start) / 2;
        TreeNode* root = new TreeNode(nums[mid]);

        root->left = sortedArrayToBSTCore(nums, start, mid-1);
        root->right = sortedArrayToBSTCore(nums, mid+1, end);

        return root;
    }

};
