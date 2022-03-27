class Solution {
    
    typedef long long LL;
    
public:
    vector<LL> kthPalindrome(vector<int>& queries, int intLength) {
        int n = queries.size();
        vector<LL> res(n, -1);
        if (intLength % 2) {
            int base = intLength / 2;
            LL start = (LL)pow(10, base), end = (LL)pow(10, base + 1) - 1;
            LL len = end - start + 1;
            for (int i = 0;i<n;++i) {
                if (queries[i] > len) {
                    continue;
                } else {
                    string s1 = to_string(start + queries[i] - 1);
                    string s2 = s1.substr(0, s1.size() - 1);
                    reverse(s2.begin(), s2.end());
                    s1 = s1 + s2;
                    res[i] = stoll(s1);
                }     
            }
        } else {
            int base = intLength / 2 - 1;
            LL start = (LL)pow(10, base), end = (LL)pow(10, base + 1) - 1;
            LL len = end - start + 1;
            for (int i = 0;i<n;++i) {
                if (queries[i] > len) {
                    continue;
                } else {
                    string s1 = to_string(start + queries[i] - 1);
                    string s2 = s1;
                    reverse(s2.begin(), s2.end());
                    s1 = s1 + s2;
                    res[i] = stoll(s1);
                }     
            } 
        }
        return res;
    }
};