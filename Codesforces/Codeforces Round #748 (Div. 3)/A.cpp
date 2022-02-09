#include <iostream>
#include <cmath>

using namespace std;

int t, a, b, c;

int main() {
	cin >> t;
	while (t--) {
		cin >> a >> b >> c;
		cout << max(0, max(b, c) - a + 1) << ' ' << max(0, max(a, c) - b + 1) << ' ' << max(0, max(a, b) - c + 1) << endl;
	}
	return 0;
}