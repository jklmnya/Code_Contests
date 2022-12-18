class Solution {
    
    int foo(int x) {
        int res = 0;
        for (int i = 2;i<=x/i;i++) {
            if (x % i == 0) {
                int count = 0;
                while (x % i == 0) {
                    x /= i;
                    res += i;
                }
            }
        }
        if (x > 1) {
            res += x;
        }
        return res;
    }
    
public:
    int smallestValue(int n) {
        while (true) {
            int x = foo(n);
            if (x == n) {
                break;
            }
            n = x;
        }
        return n;
    }
};