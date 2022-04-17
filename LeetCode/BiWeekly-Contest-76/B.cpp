class Solution {
public:
	long long waysToBuyPensPencils(int total, int cost1, int cost2) {
		long long res = 0ll;
		int f = 0;
		while (f * cost1 <= total) {
			res += (long long)(total - f * cost1) / cost2;
			++res;
			++f;
		}
		return res;
	}
};