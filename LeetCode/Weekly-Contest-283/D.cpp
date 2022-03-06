class Solution {

    int gcd(int x, int y) {
        return y ? gcd(y, x % y) : x;
    }

    inline int lcm(int x, int y, int _gcd) {
        return x / _gcd * y;
    }

public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> res;
        res.push_back(nums[0]);
        for (int i = 1;i<nums.size();++i) {
            res.push_back(nums[i]);
            while (res.size() > 1) {
                int x = res.back(), y = res[res.size() - 2];
                int _gcd = gcd(x, y);
                if (_gcd == 1)
                    break;
                res.pop_back();
                res[res.size() - 1] = lcm(x, y, _gcd);
            }
        }
        return res;
    }
};