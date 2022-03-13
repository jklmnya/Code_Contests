class Solution {

    typedef long long LL;

    vector<vector<pair<int, int>>> g;
    vector<vector<pair<int, int>>> dg;
    vector<LL> d1, d2, d3;

    void dijkstra(int n, int start, vector<vector<pair<int, int>>>& g, vector<LL>& dist) {
        bool st[n];
        memset(st, 0, sizeof st);
        dist[start] = 0ll;
        priority_queue<pair<LL, int>, vector<pair<LL, int>>, greater<pair<LL, int>>> pq;
        pq.emplace(0ll, start);
        while (pq.size()) {
            auto [w1, node] = pq.top();
            pq.pop();
            if (st[node])
                continue;
            st[node] = true;
            for (auto& [next, w2] : g[node]) {
                if (dist[next] > w1 + w2) {
                    dist[next] = w1 + w2;
                    pq.emplace(dist[next], next);
                }
            }
        }
    }

public:
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        g.resize(n);
        dg.resize(n);
        d1.resize(n, LLONG_MAX);
        d2.resize(n, LLONG_MAX);
        d3.resize(n, LLONG_MAX);
        for (auto& edge : edges) {
            int s = edge[0], e = edge[1], w = edge[2];
            g[s].emplace_back(e, w);
            dg[e].emplace_back(s, w);
        }
        dijkstra(n, src1, g, d1);
        dijkstra(n, src2, g, d2);
        dijkstra(n, dest, dg, d3);
        LL res = LLONG_MAX;
        for (int i = 0;i<n;++i) {
            if (d1[i] < LLONG_MAX && d2[i] < LLONG_MAX && d3[i] < LLONG_MAX)
                res = min(res, d1[i] + d2[i] + d3[i]);
        }
        return res == LLONG_MAX ? -1 : res;
    }
};