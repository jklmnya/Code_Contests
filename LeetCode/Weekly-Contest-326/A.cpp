class Solution {
public:
    int countDigits(int num) {
        int res = 0;
        int x = num;
        while (num) {
            int t = num % 10;
            if (x % t == 0) {
                ++res;
            }
            num /= 10;
        }
        return res;
    }
};