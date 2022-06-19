class Solution {
public:
    int minimumNumbers(int num, int k) {
        if (num == 0)
            return 0;
        int t = num % 10;
        if ((k == 0 && t == 0) || num == k)
            return 1;
        int now = 0;
        for (int i = 1;i<=10;++i) {
            now += k;
            int x = now % 10;
            if (x == t && num >= now) {
                return i;
            }
        }
        return -1;
    }
};