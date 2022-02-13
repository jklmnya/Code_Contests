class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        long long sum = 0ll;
        for (int b : beans)
            sum += b;
        sort(beans.begin(), beans.end());
        long long res = LLONG_MAX;
        long long del = 0ll;
        for (int i = 0;i<beans.size();++i) {
            
            // c//out << sum << ' ' << beans[i] << ' ';
            
            long long cnt = sum - (long long)(beans.size() - i) * beans[i];
            
            // cout << cnt << '\n';
            
            res = min(res, cnt + del);
            sum -= beans[i];
            del += beans[i];
        }
        return res;
    }
};