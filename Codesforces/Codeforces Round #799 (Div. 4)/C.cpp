#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <functional>

using namespace std;

const int N = 10;
int T;
char c[N][N];
string ss;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	while (T--) {
		// getline(cin, ss);
		for (int i = 0; i < 8; ++i)
			cin >> c[i];
		bool f = false;
		for (int i = 1; i < 7; ++i) {
			for (int j = 1; j < 7; ++j) {
				if (c[i][j] == '#' && c[i - 1][j - 1] == '#'
					&& c[i - 1][j + 1] == '#' && c[i + 1][j - 1] == '#' && c[i + 1][j + 1] == '#'
					&& c[i - 1][j] == '.' && c[i][j - 1] == '.' && c[i][j + 1] == '.'
					&& c[i + 1][j] == '.') {
					cout << i + 1 << ' ' << j + 1 << '\n';
					f = true;
					break;
				}
			}
			if (f)
				break;
		}
	}
	
	
	return 0;
}