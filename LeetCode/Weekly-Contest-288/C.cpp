class Solution {
    
    static constexpr int MOD = 1e9 + 7;
    
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int num : nums)
            pq.emplace(num);
        while (pq.size() > 1 && k) {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            if (x == y) {
                ++x;
                --k;
            } else {
                int v = min(k, y - x);
                k -= v;
                x += v;
            }
            pq.emplace(x);
            pq.emplace(y);
        }
        if (k) {
            int x = pq.top();
            pq.pop();
            x += k;
            pq.emplace(x);
        }
        int res = 1;
        while (pq.size()) {
            int num = pq.top();
            pq.pop();
            res = ((long long)res * num) % MOD;
        }
        return res;
    }
};