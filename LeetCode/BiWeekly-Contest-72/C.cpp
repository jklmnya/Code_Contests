class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if (finalSum % 2)
            return {};
        vector<long long> res;
        long long cnt = 2ll;
        while (finalSum) {
            if (finalSum - cnt <= cnt) {
                res.push_back(finalSum);
                finalSum = 0;
            } else {
                res.push_back(cnt);
                finalSum -= cnt;
            }
            cnt += 2;
        }
        return res;
    }
};