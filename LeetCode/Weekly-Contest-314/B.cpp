class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        vector<int> res(n);
        int now = 0;
        for (int i = 0;i<n;++i) {
            res[i] = now ^ pref[i];
            now ^= res[i];
        }
        return res;
    }
};