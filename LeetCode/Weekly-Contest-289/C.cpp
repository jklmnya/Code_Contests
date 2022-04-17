class Solution {
public:
	int maxTrailingZeros(vector<vector<int>>& grid) {
		int n = static_cast<int>(grid.size()), m = static_cast<int>(grid[0].size());
		int res = 0;
		int f1[n][m + 1][2];
		int f2[m][n + 1][2];
		memset(f1, 0, sizeof f1);
		memset(f2, 0, sizeof f2);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				int val = grid[i][j];
				int f5 = 0, ff2 = 0;
				while (val % 5 == 0) {
					f5++;
					val /= 5;
				}
				while (val % 2 == 0) {
					ff2++;
					val /= 2;
				}
				f1[i][j + 1][0] = f1[i][j][0] + f5;
				f1[i][j + 1][1] = f1[i][j][1] + ff2;
				f2[j][i + 1][0] = f2[j][i][0] + f5;
				f2[j][i + 1][1] = f2[j][i][1] + ff2;
			}
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				int up2 = f2[j][i + 1][1];
				int up5 = f2[j][i + 1][0];
				int down2 = f2[j][n][1] - f2[j][i][1];
				int down5 = f2[j][n][0] - f2[j][i][0];
				int left2 = f1[i][j][1];
				int left5 = f1[i][j][0];
				int right2 = f1[i][m][1] - f1[i][j + 1][1];
				int right5 = f1[i][m][0] - f1[i][j + 1][0];
				res = max(res, min(up2 + left2, up5 + left5));
				res = max(res, min(up2 + right2, up5 + right5));
				res = max(res, min(down2 + left2, down5 + left5));
				res = max(res, min(down2 + right2, down5 + right5));
			}
		}
		return res;
	}
};