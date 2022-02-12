#include <iostream>
#include <string>

using namespace std;

int n;
string str;

int main() {
    cin >> n >> str;
    string ss;
    for (auto ch : str) {
        if (ch != '0')
            ss += ch;
    }
    if (ss.size() == 0) {
        cout << "YES" << '\n';
        return 0;
    }
    int x = 0;
    bool hasAns = false;
    for (int i = 0;i<ss.size() - 1;++i) {
        x += ss[i] - '0';
        if (x == 0)
            continue;
        int s = i + 1;
        bool f = true;
        while (s < ss.size()) {
            int e = s, cnt = 0;
            while (e < ss.size() && cnt < x) {
                cnt += ss[e] - '0';
                ++e;
            }
            if (cnt != x) {
                f = false;
                break;
            }
            s = e;

        }
        if (f) {
            hasAns = true;
            break;
        }
    }
    if (hasAns)
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';
    return 0;
}

作者：Dumhdurum
链接：https://www.acwing.com/activity/content/code/content/2571203/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。