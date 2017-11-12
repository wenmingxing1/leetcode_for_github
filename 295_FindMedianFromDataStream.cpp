class MedianFinder {
public:
    //剑指offer上的题，数据流中的中位数，使用最大堆和最小堆完成，保证两个堆中元素个数相同，或最小堆中多一个
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        if (((max.size() + min.size()) & 1) == 0){  //第偶数个放入最小堆
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
        else{           //第奇数个放入最大堆
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
