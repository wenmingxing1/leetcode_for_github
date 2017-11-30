class Solution {
public:
    //�����ڽ�ָoffer30�⣬���öѽ������
    int findKthLargest(vector<int>& nums, int k) {
        int length = nums.size();
        if (length == 0 || k <= 0 || k > length)
            return 0;
        vector<int> res(nums.begin(), nums.begin()+k);
        make_heap(res.begin(), res.end(), greater<int>());  //������С�ѣ����е�һ����Ϊ��Сֵ
        vector<int>::iterator iter = nums.begin()+k;
        for (; iter != nums.end(); ++iter){
            if (*iter > res[0]){    //������ڶ�����Сֵ������ӽ���
                pop_heap(res.begin(), res.end(), greater<int>());
                res.pop_back();

                res.push_back(*iter);
                push_heap(res.begin(), res.end(), greater<int>());
            }
        }   //�����д洢����ǰk���ֵ����res�еĵ�һ��ֵΪǰk���ֵ�е���Сֵ����Ϊ����
        return res[0];
    }
};
