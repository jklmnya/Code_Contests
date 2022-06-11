class Solution {
public:
	bool strongPasswordCheckerII(string ps) {
		int n = ps.size();
		if (n < 8)
			return false;
		string str = "!@#$%^&*()-+";
		unordered_set<char> ss;
		for (char ch : str)
			ss.emplace(ch);
		bool f1 = false, f2 = false, f3 = false, f4 = false, f5 = true;
		for (int i = 0; i < n; ++i) {
			if (ps[i] >= '0' && ps[i] <= '9')
				f3 = true;
			else if (ps[i] >= 'a' && ps[i] <= 'z')
				f1 = true;
			else if (ps[i] >= 'A' && ps[i] <= 'Z')
				f2 = true;
			else if (ss.count(ps[i]))
				f4 = true;
		}
		for (int i = 0; i < n - 1; ++i) {
			if (ps[i] == ps[i + 1]) {
				f5 = false;
				break;
			}
		}
		return f1 && f2 && f3 && f4 && f5;
	}
};