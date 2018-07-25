#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int length = gas.size();
        vector<int> startVec;

        for (int i = 0; i < length; ++i) {
            if (gas[i] >= cost[i])
                startVec.push_back(i);
        }

        if (startVec.empty()) return -1;

        for (auto start : startVec) {
            int have = gas[start];

            int end = start+1;
            if (start == length-1) end = 0;

            int pre;

            while (end != start) {

                if (end == 0) pre = length-1;
                else pre = end-1;

                have = have-cost[pre]+gas[end];
                if (have < cost[end]) break;

                if (end == length-1) end = 0;
                else ++end;
            }

            if (end == start) return start;
        }
        return -1;
    }
};

int main() {
    Solution solu;
    vector<int> gas1 = {1,2,3,4,5};
    vector<int> cost1 = {3,4,5,1,2};

    vector<int> gas2 = {2,3,4};
    vector<int> cost2 = {3,4,3};

    vector<int> gas3 = {3,3,4};
    vector<int> cost3 = {3,4,4};

    cout << solu.canCompleteCircuit(gas1, cost1) << endl;
    cout << endl;
    cout << solu.canCompleteCircuit(gas2, cost2) << endl;
    cout << endl;
    cout << solu.canCompleteCircuit(gas3, cost3) << endl;

    return 0;
}
