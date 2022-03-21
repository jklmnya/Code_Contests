#include <iostream>
#include <unordered_map>

using namespace std;

int n;
int ss[16] = { 1, 0, 0, 0, 1, 0, 1, 0, 2, 1, 1, 2, 0, 1, 0, 0 };
int main() {
	cin >> n;
	int res = 0;
	while (n >= 0) {
		int t = n % 16;
		res += ss[t];
		n /= 16;
		if (n == 0)
			break;
	}
	cout << res << '\n';
	return 0;
}