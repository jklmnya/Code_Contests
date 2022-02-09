#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int T;
string a, b;

int cnt[26];

int main() {
	cin >> T;
	while (T--) {
		cin >> a >> b;
		memset(cnt, 0, sizeof cnt);
		for (auto ch : a)
			++cnt[ch - 'a'];
		string res;
		if (b[0] == 'a' && cnt[0]) {
			for (int i = 0; i < cnt[0]; ++i)
				res += 'a';
			if (b[1] == 'b') {
				for (int i = 0; i < cnt[2]; ++i)
					res += 'c';
				for (int i = 0; i < cnt[1]; ++i)
					res += 'b';
			}
			else {
				for (int i = 0; i < cnt[1]; ++i)
					res += 'b';
				for (int i = 0; i < cnt[2]; ++i)
					res += 'c';
			}
			for (int i = 3; i < 26; ++i) {
				for (int j = 0; j < cnt[i]; ++j)
					res += (char)(i + 'a');
			}
		}
		else {
			for (int i = 0; i < 26; ++i) {
				for (int j = 0; j < cnt[i]; ++j)
					res += (char)(i + 'a');
			}
		}
		cout << res << endl;
	}
	return 0;
}