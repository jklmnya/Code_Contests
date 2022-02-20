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
    ListNode* mergeNodes(ListNode* head) {
        vector<int> vv;
        while (head) {
            vv.push_back(head->val);
            head = head->next;
        }
        ListNode* res = new ListNode();
        ListNode* node = res;
        int n = static_cast<int>(vv.size());
        int s = 0;
        while (s < n) {
            int e = s + 1;
            int cnt = 0;
            while (e < n && vv[e] != 0) {
                cnt += vv[e];
                ++e;
            }
            if (cnt) {
                node->next = new ListNode(cnt);
                node = node->next;
            }
            s = e;
        }
        return res->next;
    }
};