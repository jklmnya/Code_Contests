class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string str = to_string(num);
        int res = 0;
        for (int s = 0;s + k <= str.size();++s) {
            string ss = str.substr(s, k);
            // cout << ss << '\n';
            int f = 0;
            for (char ch : ss)
                f = f * 10 + (ch - '0');
            if (f > 0 && num % f == 0)
                ++res;
        }
        return res;
    }
};