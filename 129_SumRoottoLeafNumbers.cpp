#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution1 {
public:
    int sumNumbers(TreeNode* root) {
        if (root == nullptr) return 0;
        int sum = 0;
        int num = 0;

        vector<int> nums;
        number(root, nums, num);

        for (auto i : nums) {
            sum += i;
        }
        return sum;
    }

private:
    void number(TreeNode* root, vector<int>& nums, int& num) {
        num = num * 10 + root->val;
        bool isLeaf = root->left == nullptr && root->right == nullptr;

        if (isLeaf) {
            nums.push_back(num);
        }
        else {
            if (root->left) number(root->left, nums, num);
            if (root->right) number(root->right, nums, num);
        }

        num = (num - root->val)/10;     //  num /= 10
    }
};

//另一种解法,不需要辅助空间
class Solution2 {
public:
    int sumNumbers(TreeNode *root) {
        return sumNumbersDFS(root, 0);
    }
    int sumNumbersDFS(TreeNode *root, int sum) {
        if (!root) return 0;
        sum = sum * 10 + root->val;
        if (!root->left && !root->right) return sum;
        return sumNumbersDFS(root->left, sum) + sumNumbersDFS(root->right, sum);
    }
};

int main() {
    Solution1 solu1;
    Solution2 solu2;

    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);

    node1->left = node2;
    node1->right = node3;

    cout << solu1.sumNumbers(node1) << endl;
    cout << solu2.sumNumbers(node1) << endl;
}
