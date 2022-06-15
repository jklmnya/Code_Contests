#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <functional>

using namespace std;

int T, a, b, c, d;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> a >> b >> c >> d;
		int res = 0;
		if (b > a)
			++res;
		if (c > a)
			++res;
		if (d > a)
			++res;
		cout << res << '\n';
	}
	
	
	
	return 0;
}