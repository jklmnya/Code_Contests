#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int q;
string x, y;

unordered_set<string> s;
unordered_map<string, string> ans;
unordered_map<string, string> vv;

int main() {
	cin >> q;
	while (q--) {
		cin >> x >> y;
		if (!s.count(x)) {
			ans.emplace(x, y);
		}
		else {
			string root = vv[x];
			while (vv.count(root))
				root = vv[root];
			ans[root] = y;
		}
		vv.emplace(y, x);
		s.emplace(x);
		s.emplace(y);
	}
	cout << ans.size() << '\n';
	for (auto& [k, v] : ans)
		cout << k << ' ' << v << '\n';
	return 0;
}

���ߣ�Dumhdurum
���ӣ�https ://www.acwing.com/activity/content/code/content/2628288/
��Դ��AcWing
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������