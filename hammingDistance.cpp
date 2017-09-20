#include<iostream>

using namespace std;

class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        return number(x^y);
    }
private:
    int number(int num)
    {
        int count = 0;
        while (num)
        {
            ++count;
            num = num & (num - 1);
        }
        return count;
    }
};

int main()
{
    Solution solu;
    cout << solu.hammingDistance(1,15) << endl;

    return 0;
}
