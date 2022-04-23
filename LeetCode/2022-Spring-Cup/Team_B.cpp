class Solution {
    
    struct S {
        int x, y, k;
        S(int _x, int _y, int _k) : x(_x), y(_y), k(_k) {}
    };
    
    const int dx[4] = { -1, 1, 0, 0 };
    const int dy[4] = { 0, 0, -1, 1 };
    unordered_map<char, int> mm;
    
public:
    int conveyorBelt(vector<string>& matrix, vector<int>& start, vector<int>& end) {
        mm.emplace('^', 0);
        mm.emplace('v', 1);
        mm.emplace('<', 2);
        mm.emplace('>', 3);
        int n = matrix.size(), m = matrix[0].size();
        int st[n][m];
        memset(st, 0x3f, sizeof st);
        queue<S> q;
        int res = INT_MAX;
        q.emplace(start[0], start[1], 0);
        while (q.size()) {
            auto [x, y, k] = q.front();
            q.pop();
            if (x == end[0] && y == end[1]) {
                res = min(res, k);
                continue;
            }
            if (k >= st[x][y])
                continue;
            st[x][y] = k;
            int dir = mm[matrix[x][y]];
            for (int t = 0;t<4;++t) {
                int tx = x + dx[t], ty = y + dy[t];
                if (tx < 0 || tx >= n || ty < 0 || ty >= m)
                    continue;
                if (t == dir)
                    q.emplace(tx, ty, k);
                else
                    q.emplace(tx, ty, k + 1);
            }
        }
        return res;
    }
};