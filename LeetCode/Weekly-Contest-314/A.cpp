class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int f = -1, res = -1;
        int last = 0;
        for (auto& log : logs) {
            int cnt = log[1] - last;
            
            // cout << cnt << '\n';
            
            if (cnt > f) {
                f = cnt;
                res = log[0];
            } else if (cnt == f) {
                res = min(res, log[0]);
            }
            last = log[1];
        }
        return res;
    }
};