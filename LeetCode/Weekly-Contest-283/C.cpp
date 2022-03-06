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
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, pair<int, int>> vv;
        unordered_set<int> s1, s2;
        for (auto& d : descriptions) {
            int rt = d[0], ch = d[1];
            bool f = d[2];
            if (!vv.count(rt))
                    vv[rt] = { -1, -1 };
            if (f)
                vv[rt].first = ch;
            else
                vv[rt].second = ch;
            s1.emplace(rt);
            s1.emplace(ch);
            s2.emplace(ch);
        }
        int root = -1;
        for (int node : s1) {
            if (!s2.count(node)) {
                root = node;
                break;
            }
        }
        TreeNode* res = new TreeNode(root);
        TreeNode* node = res;
        queue<TreeNode*> q;
        q.emplace(node);
        int ss = 1;
        while (q.size()) {
            for (int i = 0;i<ss;++i) {
                auto now = q.front();
                q.pop();
                int val = now->val;
                if (vv[val].first > 0) {
                    TreeNode* left = new TreeNode(vv[val].first);
                    now->left = left;
                    q.emplace(left);
                }
                if (vv[val].second > 0) {
                    TreeNode* right = new TreeNode(vv[val].second);
                    now->right = right;
                    q.emplace(right);
                }
            }
            ss = q.size();
        }
        return res;
    }
};