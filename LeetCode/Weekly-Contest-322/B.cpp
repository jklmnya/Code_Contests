class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long res = 0ll;
        int n = skill.size();
        sort(skill.begin(), skill.end());
        int i = 0, j = n - 1;
        int sum = skill[i] + skill[j];
        while (i < j) {
            if (skill[i] + skill[j] != sum) {
                return -1ll;
            }
            res += (long long)skill[i] * skill[j];
            ++i;
            --j;
        }
        return res;
    }
};