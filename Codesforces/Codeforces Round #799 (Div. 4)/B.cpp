#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <functional>

using namespace std;

int num;
int T, n;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	unordered_map<int, int> vv;

	cin >> T;
	while (T--) {
		vv.clear();
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> num;
			++vv[num];
		}
		int res = 0;
		int x = 0, y = 0;
		for (auto& [k, v] : vv) {
			if (v % 2) {
				++x;
			}	
			else {
				++y;
			}
		}
		res = x;
		if (y % 2)
			res += max(0, y - 1);
		else
			res += y;
		cout << res << '\n';
	}
	
	
	
	return 0;
}