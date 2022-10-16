class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        for (int i = 0;i<=num;++i) {
            string s = to_string(i);
            reverse(s.begin(), s.end());
            int x = stoi(s);
            if (i + x == num)
                return true;
        }
        return false;
    }
};