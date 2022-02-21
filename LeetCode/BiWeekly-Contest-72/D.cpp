class Solution {

    typedef long long LL;

    int n;
    vector<int> tree_arr;

    inline int lowbit(int x){
        return x & (-x);
    }

    void update(int val, int idx) {
        while (idx <= n) {
            tree_arr[idx] += val;
            idx += lowbit(idx);
        }
    }

    int getSum(int idx) {
        int ans = 0;
        while (idx >= 1) {
            ans += tree_arr[idx];
            idx -= lowbit(idx);
        }
        return ans;
    }

public:
    LL goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        LL res = 0ll;
        n = static_cast<int>(nums1.size());
        tree_arr.resize(n + 1);
        unordered_map<int, int> vv;
        for (int i = 0;i<n;++i)
            vv.emplace(nums2[i], i + 1);
        for (int num : nums1) {
            int idx = vv[num];
            int left = getSum(idx - 1);
            int right = n - idx - (getSum(n) - getSum(idx));
            res += 1LL * left * right;
            update(1, idx);
        }
        return res;
    }
};