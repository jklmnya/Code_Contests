class Solution {
    
    const int dx[4] = {-1, 1, 0, 0};
    const int dy[4] = {0, 0, -1, 1};
    
    struct S {
        int x, y, val;
        S(int x_, int y_, int val_) : x(x_), y(y_), val(val_) {}
        bool operator<(const S& s) const {
            return val > s.val;
        }
    };
    
public:
    vector<int> maxPoints(vector<vector<int>>& g, vector<int>& qs) {
        int k = qs.size();
        vector<int> res(k);
        vector<pair<int, int>> vec(k);
        for (int i = 0;i<k;++i) {
            vec.push_back( {qs[i], i} );
        }
        sort(vec.begin(), vec.end(), [](const auto& p1, const auto& p2) {
           return p1.first < p2.first; 
        });
        
        int n = g.size(), m = g[0].size();
        vector<vector<bool>> st(n, vector<bool>(m));
        priority_queue<S> pq;
        pq.emplace(0, 0, g[0][0]);
        int ans = 0;
        
        for (auto& [v, idx] : vec) {
            while (pq.size() && pq.top().val < v && ans < n * m) {
                auto [x, y, val] = pq.top();
                pq.pop();
                if (st[x][y]) {
                    continue;
                }
                ++ans;
                st[x][y] = true;
                for (int i = 0;i<4;++i) {
                    int tx = x + dx[i], ty = y + dy[i];
                    if (tx < 0 || tx >= n || ty < 0 || ty >= m || st[tx][ty]) {
                        continue;
                    }
                    pq.emplace(tx, ty, g[tx][ty]);
                }
            }
            res[idx] = ans;
        }
        
        return res;
    }
};