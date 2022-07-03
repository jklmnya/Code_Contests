/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int n, int m, ListNode* head) {
        vector<vector<int>> res(n, vector<int>(m, -1));
        int row_start = 0, row_end = n - 1, col_start = 0, col_end = m - 1;
        int control = -1;
        while (head) {
            control++;
            if (control % 4 == 0) {
                for (int i = col_start;i<=col_end && head;i++) {
                    res[row_start][i] = head->val;
                    head = head->next;
                }
                row_start++;
            } else if (control % 4 == 1) {
                for (int i = row_start;i<=row_end && head;i++) {
                    res[i][col_end] = head->val;
                    head = head->next;
                }
                col_end--;
            } else if (control % 4 == 2) {
                for (int i = col_end;i>=col_start && head;i--) {
                    res[row_end][i] = head->val;
                    head = head->next;
                }
                row_end--;
            } else {
                for (int i = row_end;i>=row_start && head;i--) {
                    res[i][col_start] = head->val;
                    head = head->next;
                }
                col_start++;
            }
        }
        return res;
    }
};