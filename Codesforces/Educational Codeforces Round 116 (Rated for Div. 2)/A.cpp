#include <iostream>
#include <string>

using namespace std;

int t;
string ss;

int main() {
	cin >> t;
	while (t--) {
		cin >> ss;
		if (ss[0] != ss[ss.size() - 1]) {
			if (ss[0] == 'a')
				ss[0] = 'b';
			else
				ss[0] = 'a';
		}
		cout << ss << endl;
	}
	return 0;
}