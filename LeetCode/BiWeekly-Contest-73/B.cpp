class Solution {

	struct S {
		int idx, num, x;
		S(int _idx, int _num, int _x) : idx(_idx), num(_num), x(_x) { }
		bool operator<(const S& s) const {
			if (x == s.x)
				return idx < s.idx;
			return x < s.x;
		}
	};

	inline int getX(vector<int>& mapping, int num) {
		int res = 0;
		string ss = to_string(num);
		for (char ch : ss) {
			int y = mapping[ch - '0'];
			res = res * 10 + y;
		}
		return res;
	}

public:
	vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
		int n = static_cast<int>(nums.size());
		vector<S> vv;
		vv.reserve(n);
		for (int i = 0; i < n; ++i) {
			int x = getX(mapping, nums[i]);
			vv.emplace_back(i, nums[i], x);
		}
		sort(vv.begin(), vv.end());
		for (int i = 0; i < n; ++i)
			nums[i] = vv[i].num;
		return nums;
	}
};