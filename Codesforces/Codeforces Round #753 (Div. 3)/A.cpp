#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const int N = 26;

int t;
string s1, s2;
int ss[N];

int main() {
	cin >> t;
	while (t--) {
		cin >> s1 >> s2;
		for (int i = 0; i < N; ++i)
			ss[s1[i] - 'a'] = i + 1;
		int res = 0;
		for (int i = 1; i < s2.size(); ++i)
			res += abs(ss[s2[i] - 'a'] - ss[s2[i - 1] - 'a']);
		cout << res << endl;
	}
	return 0;
}