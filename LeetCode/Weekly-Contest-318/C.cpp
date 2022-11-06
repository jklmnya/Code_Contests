class Solution {
    
    struct S {
        int val, id;
        S(int val_, int id_) : val(val_), id(id_) {}
        bool operator< (const S& s) const {
            if (s.val == val) {
                return id > s.id;
            }
            return val > s.val;
        }
    };
    
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        using LL = long long;
        LL res = 0ll;
        priority_queue<S> pq;
        
        int n = costs.size(), m = candidates;
        int i = 0, j = n - 1;
        
        while (i <= j && m > 0) {
            pq.emplace(costs[i], i);
            ++i;
            --m;
        }
        m = candidates;
        while (i < j && m > 0) {
            pq.emplace(costs[j], j);
            --j;
            --m;
        }
        
        while (k > 0) {
            auto [val, id] = pq.top();
            pq.pop();
            res += val;
            if (i <= j) {
                if (id <= i) {
                    pq.emplace(costs[i], i);
                    ++i;
                } else {
                    pq.emplace(costs[j], j);
                    --j;
                }
            }
            --k;
        }
        
        return res;
    }
};