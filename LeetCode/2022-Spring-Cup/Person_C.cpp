/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    
    vector<int> vv;
    
    void dfs(TreeNode* node) {
        if (node) {
            dfs(node->left);
            vv.push_back(node->val);
            dfs(node->right);
        }
    }
    
public:
    int getNumber(TreeNode* root, vector<vector<int>>& ops) {
        
        dfs(root);
        
        unordered_map<int, int> mm;
        for (int i = 0;i<vv.size();++i)
            mm.emplace(vv[i], i);
        
        int res = 0;
        map<int, int> q;
        q.emplace(-100, -1);
        q.emplace(0, vv.size() - 1);
        q.emplace(100005, 100006);
        
        vector<int> d;
        vector<pair<int, int>> a;
        
        for (int i = ops.size() - 1;i>=0;--i) {
            int t = ops[i][0], left = ops[i][1], right = ops[i][2];
            left = mm[left], right = mm[right];
            auto iter = q.upper_bound(right);
            --iter;
            int ans = 0;
            while (iter->second >= left) {
                int fl = max(left, iter->first), fr = min(right, iter->second);
                ans += max(0, fr - fl + 1);
                if (fr < iter->second)
                    a.emplace_back(fr + 1, iter->second);
                if (fl > iter->first)
                    a.emplace_back(iter->first, fl - 1);
                d.emplace_back(iter->first);
                if (iter == q.begin())
                    break;
                --iter;
            }
            if (t == 1)
                res += ans;
            for (int l : d)
                q.erase(l);
            for (auto& [l, r] : a)
                q.emplace(l, r);
            d.clear();
            a.clear();
        }
        return res;
    }
};