class Solution {
    
    struct S {
        int id;
        long long t;
        S(int _id, long long _t) : id(_id), t(_t) {}
        bool operator<(const S& s) const {
            if (t == s.t)
                return id > s.id;
            return t >= s.t;
        }
    };
    
public:
    int mostBooked(int n, vector<vector<int>>& m) {
        vector<int> res(105);
        sort(m.begin(), m.end(), [](const vector<int>& v1, const vector<int>& v2) {
            return v1[0] < v2[0];
        });
        
        map<int, int> ss;
        priority_queue<S> pq;
        for (int i = 0;i<n;++i) {
            pq.emplace(i, 0ll);
        }
            
        
        for (const auto& k : m) {
            int s = k[0], e = k[1] - 1;
            while (pq.size() && pq.top().t <= s) {
                ss.emplace(pq.top().id, pq.top().t);
                pq.pop();
            }
            if (ss.size()) {
                int idx = ss.begin()->first;
                long long t = ss.begin()->second;
                // auto [idx, t] = ss.begin();
                res[idx]++;
                ss.erase(ss.begin());
                pq.emplace(idx, e + 1);
            } else {
                auto [idx, t] = pq.top();
                pq.pop();
                res[idx]++;
                pq.emplace(idx, t + e - s + 1);
            }
        }
        
        int ans = 0, cnt = 0;
        for (int i = 0;i<n;++i) {
            if (res[i] > cnt) {
                cnt = res[i];
                ans = i;
            }
        }
        return ans;
    }
};