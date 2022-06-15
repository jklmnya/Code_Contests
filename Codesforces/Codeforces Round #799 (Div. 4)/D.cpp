#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_set>
#include <functional>
#include <cstring>

using namespace std;

const int N = 200005;
int T, n;
string str;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	unordered_set<int> ss;

	cin >> T;
	while (T--) {
		cin >> str >> n;
		ss.clear();
		int hh = (str[0] - '0') * 10 + str[1] - '0';
		int mm = (str[3] - '0') * 10 + str[4] - '0';
		int tt = hh * 60 + mm;
		int ahh = n / 60, amm = n % 60;

		int res = 0;
		while (!ss.count(tt)) {
			ss.emplace(tt);

			// cout << hh << ' ' << tt << '\n';

			if (hh / 10 == mm % 10 && hh % 10 == mm / 10)
				++res;

			mm = mm + amm;
			if (mm >= 60)
				hh = hh + 1;
			mm = mm % 60;
			hh = hh + ahh;
			hh = hh % 24;
			tt = hh * 60 + mm;
		}

		cout << res << '\n';
	}

	return 0;
}