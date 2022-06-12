class Solution {
public:
    double calculateTax(vector<vector<int>>& b, int income) {
        double res = 0ll;
        for (int i = 0;i<b.size();++i) {
            if (i == 0) {
                res += min(b[i][0], income) * (double)(b[i][1]) / 100;
            } else {
                res += (min(b[i][0], income) - b[i - 1][0]) * (double)(b[i][1]) / 100;
            }
            if (b[i][0] >= income)
                break;
        }
        return res;
    }
};