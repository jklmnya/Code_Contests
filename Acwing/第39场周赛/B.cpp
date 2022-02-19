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

作者：Dumhdurum
链接：https ://www.acwing.com/activity/content/code/content/2628288/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。