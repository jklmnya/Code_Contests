/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    
    vector<int> res;
    vector<pair<int, int>> hh;
    vector<int> depth;
    vector<int> vv;
    vector<int> fa;
    
    int n;
    
    int getNode(TreeNode* node) {
        if (node) {
            int res = 1 + getNode(node->left) + getNode(node->right);
            return res;
        }
        return 0;
    }
    
    int getMaxDepth(TreeNode* node, int d, int father) {
        if (node) {
            depth[node->val] = d;
            fa[node->val] = father;
            int left = getMaxDepth(node->left, d + 1, node->val);
            int right = getMaxDepth(node->right, d + 1, node->val);
            if (left < right)
                swap(left, right);
            hh[node->val] = {left, right};
            return 1 + left;
        }
        return 0;
    }
    
    void dfs(TreeNode* node, int maxV) {
        if (node) {
            vv[node->val] = max(maxV, hh[node->val].second + depth[node->val]);
            dfs(node->left, vv[node->val]);
            dfs(node->right, vv[node->val]);
        }
    }
    
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& qs) {
        int m = qs.size();
        n = getNode(root);
        res.reserve(m);
        hh.resize(n + 1);
        depth.resize(n + 1);
        vv.resize(n + 1);
        fa.resize(n + 1);
        
        getMaxDepth(root, 0, 0);
        dfs(root, 0);
        
        int rt = root->val;
        for (int q : qs) {
            int ans = 0;
            if (depth[q] + hh[q].first == hh[rt].first) {
                ans = vv[fa[q]];
            } else {
                ans = hh[rt].first;
            }
            res.push_back(ans);
        }
        
        return res;
    }
};