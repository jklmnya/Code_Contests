class Solution {
    
    const int val = 2e9 + 10;
    
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        int res = 0;
        sort(tiles.begin(), tiles.end(), [](const vector<int>& v1, const vector<int>& v2) {
           return v1[0] < v2[0];
        });
        tiles.push_back(std::move(vector<int> { val, val + 5 }));
        vector<int> v1(tiles.size());
        vector<int> v2(tiles.size());
        for (int i = 0;i<tiles.size();++i) {
            v1[i] = tiles[i][0];
            v2[i] = tiles[i][1];
        }
        
        int f[tiles.size() + 1];
        memset(f, 0, sizeof f);
        for (int i = 1;i<=tiles.size();++i) 
            f[i] = f[i - 1] + (v2[i - 1] - v1[i - 1] + 1);
        for (int i = 0;i<tiles.size() - 1;++i) {
            auto iter = upper_bound(v1.begin(), v1.end(), v1[i] + carpetLen - 1);
            --iter;
            int idx = iter - v1.begin();
            res = max(res, min(v1[i] + carpetLen - 1, v2[idx]) - v1[idx] + 1 + f[idx] - f[i]);
        }
        return res;
    }
};