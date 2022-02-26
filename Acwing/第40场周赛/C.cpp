#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

string a, b;
int cnt[10];

bool dfs(int idx, int n, string& now, bool same) {
    if (idx == n)
        return true;
    int low = idx == 0 ? 1 : 0;
    for (int i = 9;i>=low;--i) {
        if (cnt[i]) {
            int val = b[idx] - '0';
            if (same) {
                if (i == val) {
                    now += (char)(i + '0');
                    --cnt[i];
                    if (dfs(idx + 1, n, now, true))
                        return true;
                    now.pop_back();
                    ++cnt[i];
                } else if (i < val) {
                    now += (char)(i + '0');
                    --cnt[i];
                    if (dfs(idx + 1, n, now, false))
                        return true;
                    now.pop_back();
                    ++cnt[i];
                } else {
                    
                }
            } else {
                for (int i = 9;i>=0;--i) {
        	        while (cnt[i]) {
        	            now += (char)(i + '0');
        	            --cnt[i];
        	        }
        	    }
        	    return true;
            }
        }
    }
    return false;
}

int main() {
	cin >> a >> b;
	for (char ch : a)
	    ++cnt[ch - '0'];
	if (a.size() < b.size()) {
	    for (int i = 9, idx = 0;i>=0;--i) {
	        while (cnt[i]) {
	            a[idx++] = (char)(i + '0');
	            --cnt[i];
	        }
	    }
	    cout << a << '\n';
	} else {
	    string res = "";
	    dfs(0, static_cast<int>(a.size()), res, true);
	    cout << res << '\n';
	}
	return 0;
}