#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        combinationCore(candidates, target, res, temp, 0);
        return res;
    }
private:
    void combinationCore(vector<int>& candidates, int target, vector<vector<int>>& res, vector<int>& temp, int start) {
        if (target == 0) {
            res.push_back(temp);
        }

        for (int i = start; i < candidates.size(); ++i) {

            if (target >= candidates[i]) {
                //只对第一个进行递归，如果之前出现过，则跳过
                if ( i > start && candidates[i] == candidates[i-1]) continue;
                temp.push_back(candidates[i]);
                combinationCore(candidates, target-candidates[i], res, temp, i+1);
                temp.pop_back();
            }
        }
    }
};

int main() {
    Solution solu;
    vector<int> vec = {10,1,2,7,6,1,5};
    int target = 8;
    vector<vector<int>> res = solu.combinationSum2(vec, target);

    for (auto v : res) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}
