class Solution {
public:
    //类似于剑指offer30题，利用堆解决问题
    int findKthLargest(vector<int>& nums, int k) {
        int length = nums.size();
        if (length == 0 || k <= 0 || k > length)
            return 0;
        vector<int> res(nums.begin(), nums.begin()+k);
        make_heap(res.begin(), res.end(), greater<int>());  //构造最小堆，堆中第一个数为最小值
        vector<int>::iterator iter = nums.begin()+k;
        for (; iter != nums.end(); ++iter){
            if (*iter > res[0]){    //如果大于堆中最小值，则添加进来
                pop_heap(res.begin(), res.end(), greater<int>());
                res.pop_back();

                res.push_back(*iter);
                push_heap(res.begin(), res.end(), greater<int>());
            }
        }   //最后堆中存储的是前k大的值，而res中的第一个值为前k大的值中的最小值，即为所求
        return res[0];
    }
};
