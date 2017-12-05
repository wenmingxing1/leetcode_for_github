//剑指offer第29题
class Solution {
public:
    /*
    //完全排序方式
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int middle = nums.size()/2;
        return nums[middle];
    }
    */

    //partation做法
    int majorityElement(vector<int>& nums) {
        int length = nums.size();
        int middle = length >> 1;
        int start = 0;
        int end = length - 1;
        int index = Partation(nums, start, end);

        //直到找到middle
        while (index != middle){
            if (index > middle){
                end = index - 1;
                index = Partation(nums, start, end);
            }
            else if (index < middle){
                start = index + 1;
                index = Partation(nums, start, end);
            }
        }
        return nums[middle];
    }
private:
    int Partation(vector<int>& nums, int start, int end){
        int small = start - 1;
        //int index = start;
        int temp = Random(start, end);
        //交换标准
        Swap(&nums[temp], &nums[end]);
        for (int i = start; i < end; ++i){
            if (nums[i] < nums[end]){
                ++small;
                if (small != i)
                    Swap(&nums[small], &nums[i]);
            }
        }
        ++small;
        Swap(&nums[small], &nums[end]);

        return small;
    }

    int Random(int start, int end){
        if (end > start)
            return start + rand() % (end - start);
        else
            return 0;
    }

    void Swap(int* i, int* j){
        int temp = *i;
        *i = *j;
        *j = temp;
    }
};
