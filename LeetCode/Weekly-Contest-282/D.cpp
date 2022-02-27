typedef long long LL;

class Solution {
    
public:
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
        int n = static_cast<int>(tires.size());
        LL minTime[numLaps + 1];
        LL lastTime[n];
        unordered_map<int, int> vv;
        LL v = INT_MAX;
        for (int i = 0;i<n;++i) {
            lastTime[i] = tires[i][0];
            v = min(v, lastTime[i]);
            vv.insert( {i, tires[i][1]} );
        }
        minTime[1] = v;
        vector<int> del;
        for (int i = 2;i<=numLaps;++i) {
            LL ans = INT_MAX;
            for (auto& [idx, r] : vv) {
                lastTime[idx] +=  tires[idx][0] * (LL)pow(r, i - 1);
                if (lastTime[idx] >= INT_MAX)
                    del.emplace_back(idx);
                else
                    ans = min(ans, lastTime[idx]);
            }
            minTime[i] = ans;
            for (int d : del)
                vv.erase(d);
            del.clear();
        }
        
        // for (int i = 1;i<=numLaps;++i) {
        //     cout << i << ' ' << minTime[i] << '\n';
        // }
        
        LL f[numLaps + 1];
        f[1] = minTime[1];
        for (int i = 2;i<=numLaps;++i) {
            f[i] = minTime[i];
            for (int j = i - 1;j>=1;--j)
                f[i] = min(f[i], f[j] + minTime[i - j] + changeTime);
        }
        
        // for (int i = 1;i<=numLaps;++i) {
        //     cout << f[i] << ' ';
        // }
        
        return f[numLaps];
    }
};