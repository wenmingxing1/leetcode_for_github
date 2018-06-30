#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    /*暴力法，超时*/
    /*
    int maxArea(vector<int>& height) {
        int resMax = 0;
        int newMax = 0;

        for (int i = 0; i < height.size(); ++i) {
            for (int j = i+1; j < height.size(); ++j) {
                newMax = (j-i) * (height[i]<height[j] ? height[i] : height[j]);
                resMax = max(resMax, newMax);
            }
        }
        return resMax;
    }
    */
    int maxArea(vector<int>& height) {
        int resMax = 0;
        int newMax = 0;
        int left = 0;
        int right = height.size()-1;
        //以宽度最大开始，后续之后变高的时候才进行运算，其他的跳过
        while (left < right) {
            int h = min(height[left], height[right]);
            newMax = (right-left) * h;
            resMax = max(newMax, resMax);

            while (height[left] <= h && left < right) ++left;
            while (height[right] <= h && left < right) --right;

        }
        return resMax;
    }

};

int main() {
    vector<int> vec = {1,3,5,7,8,6};
    Solution solu;
    cout << solu.maxArea(vec) << endl;

    return 0;
}
