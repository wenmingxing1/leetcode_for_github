class Solution {
public:
    //��ָoffer�ϵ��⣬˫�����
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int length = nums.size();
        std::deque<int> index;
        if (k <= length && k >= 0){
            for (int i = 0; i < length; ++i){
                while (!index.empty() && nums[i] > nums[index.back()])  //��Ԫ�ش���deque�����һ��Ԫ��
                    index.pop_back();
                if (!index.empty() && (i - index.front() >= k))     //front�Ѿ������ڻ�������
                    index.pop_front();
                index.push_back(i);     //��Ԫ�ؽ���deque

                if (i+1 >= k)   //��ʼ��¼���ֵ
                    res.push_back(nums[index.front()]);
            }
        }
        return res;
    }
};
