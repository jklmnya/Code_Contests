class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        int res = 0;
        bool st[n * n];
        memset(st, 0, sizeof st);
        for (auto& d : dig) {
            int x = d[0], y = d[1];
            st[x * n + y] = true;
        }
        for (auto& a : artifacts) {
            int x1 = a[0], y1 = a[1], x2 = a[2], y2 = a[3];
            bool f = true;
            for (int i = x1;i<=x2;++i) {
                for (int j = y1;j<=y2;++j) {
                    int idx = i * n + j;
                    if (!st[idx]) {
                        f = false;
                        break;
                    }
                }
            }
            if (f)
                ++res;
        }
        return res;
    }
};