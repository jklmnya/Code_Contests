#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set>
#include <iostream>

using namespace std;

const int N = 3005;

int n;
int ss[N];

int main() {
	cin >> n;
	for (int i = 0;i<n;++i)
	    cin >> ss[i];
	sort(ss, ss + n);
	int res = 0;
	for (int i = 1;i<n;++i) {
	    if (ss[i] > ss[i - 1])
	        continue;
	    int val = ss[i];
	    ss[i] = ss[i - 1] + 1;
	    res += ss[i] - val;
	}
	cout << res << '\n';
	return 0;
}