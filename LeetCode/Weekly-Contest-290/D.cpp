class Solution {
    
    struct S {
        int idx, t;
        S(int _idx, int _t) : idx(_idx), t(_t) {}
        bool operator<(const S& s) const {
            return t < s.t;
        }
    };
    
    static bool cmp(const vector<int>& v1, const vector<int>& v2) {
        return v1[0] < v2[0];
    }
    
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        int n = persons.size();
        vector<S> vv;
        vv.reserve(n);
        for (int i = 0;i<n;++i)
            vv.emplace_back(i, persons[i]);
        sort(vv.begin(), vv.end());
        sort(flowers.begin(), flowers.end(), cmp);
        priority_queue<int, vector<int>, greater<int>> pq;
        int fidx = 0;
        vector<int> res(n);
        for (auto& [idx, t] : vv) {
            while (fidx < flowers.size() && flowers[fidx][0] <= t) {
                pq.emplace(flowers[fidx][1]);
                ++fidx;
            }
            while (pq.size() && pq.top() < t)
                pq.pop();
            res[idx] = pq.size();
        }
        return res;
    }
};