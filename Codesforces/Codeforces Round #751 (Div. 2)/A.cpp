#include <iostream>
#include <string>

using namespace std;

int T;

string ss;

int main() {
    cin >> T;
    while (T--) {
        cin >> ss;
        char ch = ss[0];
        int idx = 0;
        string a = "", b = "";
        for (int i = 0;i<ss.size();++i) {
            if (ss[i] < ch) {
                ch = ss[i];
                idx = i;
            }
        }
        a += ch;
        b += ss.substr(0, idx);
        b += ss.substr(idx + 1);
        cout << a << ' ' << b << endl;
    }
    return 0;
}