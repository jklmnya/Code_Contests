class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int t = 0;
        for (int i = 0;i<31;++i) {
            if ((num2 >> i) & 1)
                ++t;
        }
        int res = 0;
        
        for (int i = 30;i>=0 && t > 0;--i) {
            if ((num1 >> i) & 1) {
                res += (1 << i);
                --t;
            }
        }
        for (int i = 0;i<31 && t > 0;++i) {
            if (((num1 >> i) & 1) == 0) {
                res += (1 << i);
                --t;
            }
        }
        return res;
    }
};