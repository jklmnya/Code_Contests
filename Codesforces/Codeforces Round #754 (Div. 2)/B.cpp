#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

/*
*	greedy + two point + 分类讨论
*	
*	Case 1: ss[s] == 0, ss[e] == 1 -> ++s, --e
*	Case 2: ss[s] == 0, ss[e] == 0 -> ++s
*	Case 3: ss[s] == 1, ss[e] == 0 -> 需要交换，++s, --e
*	Case 4: ss[s] == 1, ss[e] == 1 -> --e
* 
*/
	
using namespace std;

int t, n;
string ss;

int main() {
	cin >> t;
	while (t--) {
		cin >> n >> ss;
		vector<int> v;
		int s = 0, e = n - 1;
		while (s < e) {
			if (ss[s] == '0') {
				if (ss[e] == '1')
					--e;
				++s;
			}
			else {
				if (ss[e] == '0') {
					v.emplace_back(s + 1);
					v.emplace_back(e + 1);
					++s;
				}
				--e;
			}
		}
		if (v.size()) {
			sort(v.begin(), v.end());
			cout << 1 << endl;
			cout << v.size() << ' ';
			for (auto id : v)
				cout << id << ' ';
			cout << endl;
		}
		else {
			cout << 0 << endl;
		}
	}
	return 0;
}