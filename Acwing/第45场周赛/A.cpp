#include <iostream>
#include <string>

using namespace std;

string ss;
int f[4];

int main() {
    cin >> f[0] >> f[1] >> f[2] >> f[3];
    cin >> ss;
    int res = 0;
    for (char ch : ss)
        res += f[ch - '1'];
    cout << res << '\n';
	return 0;
}