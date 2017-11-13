class Solution {
public:
    //剑指offer上的题，双向队列
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int length = nums.size();
        std::deque<int> index;
        if (k <= length && k >= 0){
            for (int i = 0; i < length; ++i){
                while (!index.empty() && nums[i] > nums[index.back()])  //新元素大于deque的最后一个元素
                    index.pop_back();
                if (!index.empty() && (i - index.front() >= k))     //front已经不属于滑动窗口
                    index.pop_front();
                index.push_back(i);     //新元素进入deque

                if (i+1 >= k)   //开始记录最大值
                    res.push_back(nums[index.front()]);
            }
        }
        return res;
    }
};
