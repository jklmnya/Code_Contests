class Solution {
public:
    int giveGem(vector<int>& gem, vector<vector<int>>& operations) {
        for (int i = 0;i<operations.size();++i) {
            int x = operations[i][0], y = operations[i][1];
            int v = gem[x] / 2;
            gem[x] -= v;
            gem[y] += v;
        }
        int maxV = INT_MIN, minV = INT_MAX;
        for (int g : gem) {
            maxV = max(maxV, g);
            minV = min(minV, g);
        }
        return maxV - minV;
    }
};