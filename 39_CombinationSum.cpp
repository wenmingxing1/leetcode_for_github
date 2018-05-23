#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;

        combinationSumCore(candidates, target, res, temp, 0);
        return res;
    }

private:
    void combinationSumCore(vector<int>& candidates, int target, vector<vector<int>>& res, vector<int>& temp, int index) {
        if (target == 0) {
            res.push_back(temp);
            return;
        }
        for (int i = index; i < candidates.size(); ++i) {
            if (target >= candidates[i]) {
                temp.push_back(candidates[i]);
                combinationSumCore(candidates, target-candidates[i], res, temp, i);
                temp.pop_back();
            }
        }
    }
};

int main() {
    vector<int> vec = {2,3,5};
    Solution solu;
    vector<vector<int>> res = solu.combinationSum(vec, 8);

    for (auto v : res) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}
