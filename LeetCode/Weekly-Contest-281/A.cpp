class Solution {
public:
    int countEven(int num) {
        int res = 0;
        for (int i = 1; i <= num; ++i) {
            int cnt = 0, x = i;
            while (x) {
                cnt += x % 10;
                x /= 10;
            }
            if (cnt % 2 == 0)
                ++res;
        }
        return res;
    }
};