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
    
    int res = 0;
    
    pair<int, int> dfs(TreeNode* root) {
        if (root) {
            auto [suml, cntl] = dfs(root->left);
            auto [sumr, cntr] = dfs(root->right);
            int sum = suml + sumr + root->val;
            int cnt = 1 + cntl + cntr;
            if (root->val == sum / cnt)
                ++res;
            return { sum, cnt };
        }
        return { 0, 0 };
    }
    
public:
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return res;
    }
};