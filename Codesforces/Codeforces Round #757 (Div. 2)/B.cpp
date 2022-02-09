#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
	ÅÅÐò + Ì°ÐÄ
*/

typedef long long LL;

const int N = 200010;

int T, n, k;

int ans[N];

struct S {
	int id, fq;
	S(int _id, int _fq) : id(_id), fq(_fq) {}
	bool operator<(const S& s) const {
		return fq > s.fq;
	}
};

vector<S> vv;

int main() {
	cin >> T;
	while (T--) {
		cin >> n;
		vv.clear();
		for (int i = 1; i <= n; ++i) {
			cin >> k;
			vv.emplace_back(i, k);
		}
		sort(vv.begin(), vv.end());
		ans[0] = 0;
		int l = 0, r = 0;
		bool f = true;
		LL res = 0ll;
		for (auto& [id, fq] : vv) {
			if (f) {
				ans[id] = ++r;
				res += (LL)fq * r;
			}
			else {
				ans[id] = --l;
				res += (LL)fq * -l;
			}
			f = !f;
		}
		cout << 2 * res << endl;
		for (int i = 0; i <= n; ++i)
			cout << ans[i] << ' ';
		cout << endl;
	}
	return 0;
}