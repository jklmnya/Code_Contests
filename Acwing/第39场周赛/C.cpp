#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

const int N = 200010;
int n;
string ss;

int f[N];

int find(int node) {
	if (node != f[node])
		f[node] = find(f[node]);
	return f[node];
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		f[i] = i;
	vector<vector<int>> g(26);
	for (int k = 0; k < n; ++k) {
		int state = 0;
		cin >> ss;
		for (char ch : ss) {
			int c = ch - 'a';
			if (!((state >> c) & 1))
				state = state | (1 << c);
		}
		for (int i = 0; i < 26; ++i) {
			if ((state >> i) & 1)
				g[i].push_back(k);
		}
	}
	for (int i = 0; i < 26; ++i) {
		for (int j = 1; j < g[i].size(); ++j)
			f[find(g[i][j])] = find(g[i][0]);
	}
	unordered_set<int> ss;
	for (int i : f)
		ss.emplace(find(i));
	cout << ss.size() << '\n';
	return 0;
}

作者：Dumhdurum
链接：https ://www.acwing.com/activity/content/code/content/2629321/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。