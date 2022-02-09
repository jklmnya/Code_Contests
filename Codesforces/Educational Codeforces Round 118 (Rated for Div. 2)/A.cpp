#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t, x1, p1, x2, p2;

vector<int> v1, v2;

int main() {
	cin >> t;
	while (t--) {
		cin >> x1 >> p1 >> x2 >> p2;
		v1.clear(); v2.clear();
		while (x1) {
			v1.emplace_back(x1 % 10);
			x1 /= 10;
		}
		while (x2) {
			v2.emplace_back(x2 % 10);
			x2 /= 10;
		}
		int len1 = v1.size() + p1, len2 = v2.size() + p2;
		if (len1 > len2) {
			cout << ">" << endl;
		}
		else if (len1 < len2) {
			cout << "<" << endl;
		}
		else {
			reverse(v1.begin(), v1.end());
			reverse(v2.begin(), v2.end());
			int s1 = 0, s2 = 0, ans = -2;
			while (s1 < v1.size() && s2 < v2.size()) {
				if (v1[s1] > v2[s2]) {
					ans = 1;
					break;
				}
				else if (v1[s1] < v2[s2]) {
					ans = -1;
					break;
				}
				else {
					++s1, ++s2;
				}
			}
			if (ans == -2) {
				while (s1 < v1.size()) {
					if (v1[s1]) {
						ans = 1;
						break;
					}
					++s1;
				}
				while (s2 < v2.size()) {
					if (v2[s2]) {
						ans = -1;
						break;
					}
					++s2;
				}
			}
			if (ans == 1) {
				cout << ">" << endl;
			}
			else if (ans == -1) {
				cout << "<" << endl;
			}
			else {
				cout << "=" << endl;
			}
		}

	}
	return 0;
}