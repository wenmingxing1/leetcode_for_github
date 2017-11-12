class MedianFinder {
public:
    //��ָoffer�ϵ��⣬�������е���λ����ʹ�����Ѻ���С����ɣ���֤��������Ԫ�ظ�����ͬ������С���ж�һ��
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        if (((max.size() + min.size()) & 1) == 0){  //��ż����������С��
            if (!max.empty() && num < max[0]){
                max.push_back(num);
                push_heap(max.begin(), max.end(), less<int>());

                num = max[0];
                pop_heap(max.begin(), max.end(), less<int>());
                max.pop_back();
            }
            min.push_back(num);
            push_heap(min.begin(), min.end(), greater<int>());
        }
        else{           //����������������
            if (!min.empty() && num > min[0]){
                min.push_back(num);
                push_heap(min.begin(), min.end(), greater<int>());

                num = min[0];
                pop_heap(min.begin(), min.end(), greater<int>());
                min.pop_back();
            }
            max.push_back(num);
            push_heap(max.begin(), max.end(), less<int>());
        }
    }

    double findMedian() {
        int size = max.size() + min.size();
        double median = 0;
        if (size > 0){
            if ((size&1) == 0)
                median = ((double)min[0] + max[0])/2;
            else
                median = (double)min[0];
        }
        return median;
    }
private:
    vector<int> min;
    vector<int> max;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
