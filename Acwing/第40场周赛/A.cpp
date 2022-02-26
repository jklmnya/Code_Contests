#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set>
#include <iostream>

using namespace std;

int n;

int main() {
	cin >> n;
	int f1 = 1, f2 = 2;
	unordered_set<int> ss;
	ss.emplace(1);
	ss.emplace(2);
	while (f1 + f2 <= n) {
	    int f3 = f1 + f2;
	    ss.emplace(f3);
	    f1 = f2;
	    f2 = f3;
	}
	string res = "";
	for (int i = 1;i<=n;++i) {
	    if (ss.count(i))
	        res += 'O';
	    else
	        res += 'o';
	}
	cout << res << '\n';
	return 0;
}