#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <functional>
#include <cstring>

using namespace std;

const int N = 200005;
int T, n, x;
int f[10], need[10];
string str;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> n;
		memset(f, 0, sizeof f);
		for (int i = 0; i < n; ++i) {
			cin >> x;
			str = to_string(x);
			++f[str.back() - '0'];
		}

		bool b = false;
		for (int i = 0; i <= 9 && !b; ++i) {
			for (int j = 0; j <= 9 && !b; ++j) {
				for (int k = 0; k <= 9 && !b; ++k) {
					str = to_string(i + j + k);
					if (str.back() == '3') {
						bool q = true;
						memset(need, 0, sizeof need);
						need[i]++;
						need[j]++;
						need[k]++;
						for (int g = 0; g < 10; ++g) {
							if (need[g] > f[g]) {
								q = false;
								break;
							}
						}
						b = q;
					}
				}
			}
		}
		if (b)
			cout << "Yes" << '\n';
		else
			cout << "No" << '\n';
	}

	return 0;
}