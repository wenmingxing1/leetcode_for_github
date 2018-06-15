#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> myMap;
        priority_queue<pair<int, int>> p;
        vector<int> res;

        for (auto n : nums) ++myMap[n];

        for (auto m : myMap) p.push({m.second, m.first}); //“‘second≈≈–Ú

        for (int i = 0; i < k; ++i) {
            res.push_back(p.top().second);
            p.pop();
        }
        return res;
    }
};

int main() {
    Solution solu;
    vector<int> nums = {1,1,1,1,2,2,2,2,2,2,3,3,3,3,4,5,5};
    vector<int> res = solu.topKFrequent(nums, 3);

    for (auto r : res)
        cout << r << " ";
    cout << endl;

    return 0;
}
