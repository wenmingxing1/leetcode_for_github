class Solution {
public:
    //½£Ö¸offerµÚ34Ìâ
    int nthUglyNumber(int n) {
        vector<int>res(n);
        res[0] = 1;
        int next = 1;
        int multi2 = 0, multi3 = 0, multi5 = 0;
        while (next < n){
            res[next] = min(res[multi2]*2, res[multi3]*3, res[multi5]*5);

            if (res[next] == res[multi2]*2)
                ++multi2;
            if (res[next] == res[multi3]*3)
                ++multi3;
            if (res[next] == res[multi5]*5)
                ++multi5;

            ++next;
        }

        return res[n-1];
    }
private:
    int min(int i, int j, int k){
        int res = i < j ? i : j;
        return res < k ? res : k;
    }
};
