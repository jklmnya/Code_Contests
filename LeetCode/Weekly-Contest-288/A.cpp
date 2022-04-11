class Solution {
public:
    int largestInteger(int num) {
        string ss = to_string(num);
        vector<int> v1, v2;
        vector<int> v3, v4;
        for (int i = 0;i<ss.size();++i) {
            int v = ss[i] - '0';
            if (v % 2) {
                v1.push_back(i);
                v3.push_back(v);
            } else {
                v2.push_back(i);
                v4.push_back(v);
            }
        }
        sort(v3.begin(), v3.end());
        sort(v4.begin(), v4.end());
        int k = v3.size() - 1;
        for (int idx : v1) {
            ss[idx] = v3[k] + '0';
            k--;
        }
        k = v4.size() - 1;
        for (int idx : v2) {
            ss[idx] = v4[k] + '0';
            k--;
        }
        return stoi(ss);
    }
};