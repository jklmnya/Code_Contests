class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        bool res = true;
        for (int i = 0;i<n;++i) {
            if (grid[i][i] == 0 || grid[i][n - i - 1] == 0) {
                res = false;
                break;
            }
        }
        for (int i = 0;i<n;++i) {
            for (int j = 0;j<n;++j) {
                if (i != j && n - i - 1 != j && grid[i][j]) {
                    res = false;
                    break;
                }
            }
        }
        return res;
    }
};