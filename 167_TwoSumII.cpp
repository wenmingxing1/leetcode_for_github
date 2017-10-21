#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> result;
    vector<int> twoSum(vector<int>& numbers, int target) {
        //vector<int> result;
        if (numbers.size() <= 0)
            return result;
        int start = 0;
        int end = numbers.size() - 1;
        while (start < end){
            //vector<int> temp;
            if (numbers[start] + numbers[end] == target){
                //temp.push_back(start+1);
                //temp.push_back(end+1);
                result.push_back(start+1);
                result.push_back(end+1);
                break;
            }
            else if (numbers[start] + numbers[end] < target){
                start++;
            }
            else
                end--;
        }
        return result;
    }
};

int main()
{
    vector<int> numbers = {2,7,11,15};
    Solution solu;
    vector<int> result;
    result = solu.twoSum(numbers, 9);
    for (int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << " ";
    }

    return 0;
}
