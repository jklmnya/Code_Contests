class Solution {
    
    using LL = long long;
    
public:
    long long makeIntegerBeautiful(long long n, int target) {
        vector<int> vv;
        while (n) {
            vv.push_back(n % 10);
            n /= 10;
        }
        
        vector<int> ans;
        for (int i = 0;i<vv.size();++i) {
            int x = accumulate(vv.begin(), vv.end(), 0);
            
            // cout << x << '\n';
            
            if (x > target) {
                ans.push_back(10 - vv[i]);
                vv[i] = 0;
                for (int j = i + 1;j<vv.size();++j) {
                    vv[j]++;
                    if (vv[j] >= 10) {
                        vv[j] = 0;
                    } else {
                        break;
                    }
                }
            } else {
                break;
            }
        }
        
        LL res = 0ll;
        for (int i = (int)ans.size() - 1;i>=0;--i) {
            res = res * 10 + ans[i];
        }
        return res;
    }
};