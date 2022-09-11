class Solution {
    
    struct Node {
        int l, r, maxVal;
    } tr[4 * 100005];

    void pushup(int u) {
        tr[u].maxVal = max(tr[u << 1].maxVal, tr[(u << 1) | 1].maxVal);
    }

    void build(int u, int l, int r) {
        tr[u].l = l, tr[u].r = r;
        if (l == r)
            return;
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build((u << 1) | 1, mid + 1, r);
    }

    void modify(int u, int pos, int val) {
        if (tr[u].l == pos && tr[u].r == pos) {
            tr[u].maxVal = val;
            return;
        }
        int mid = (tr[u].l + tr[u].r) >> 1;
        if (pos <= mid)
            modify(u << 1, pos, val);
        if (pos > mid)
            modify((u << 1) | 1, pos, val);
        pushup(u);
    }

    int query(int u, int l, int r) {
        if (tr[u].l >= l && tr[u].r <= r)
            return tr[u].maxVal;
        int mid = (tr[u].l + tr[u].r) >> 1;
        int res = 0;
        if (l <= mid)
            res = query(u << 1, l, r);
        if (r > mid)
            res = max(res, query((u << 1) | 1, l, r));
        return res;
    }
    
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        int n = nums.size();
        build(1, 1, 100005);
        int res = 1;
        for (int i = 1;i<=n;++i) {
            int num = nums[i - 1];
            if (num != 1) {
                int l = max(1, num - k), r = max(l, num - 1);
                int len = query(1, l, r);
                res = max(res, len + 1);
                modify(1, num, len + 1);
            } else {
                modify(1, 1, 1);
            }   
        }
        return res;
    }
};