#include <iostream>

using namespace std;

/*
    �ⷽ��
*/

typedef long long LL;

int t, u, v;

int main() {
    cin >> t;
    while (t--) {
        cin >> u >> v;
        cout << -(LL)u * u << ' ' << (LL)v * v << endl;
    }
    return 0;
}