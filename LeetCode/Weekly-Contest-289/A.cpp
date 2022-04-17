class Solution {
public:
	string digitSum(string ss, int k) {
		while (ss.size() > k) {
			string str = "";
			int s = 0;
			while (s < ss.size()) {
				int len = min(k, (int)ss.size() - s);
				string now = ss.substr(s, len);
				int val = 0;
				for (char c : now)
					val += c - '0';
				str += to_string(val);
				s += k;
			}
			ss = str;
		}
		return ss;
	}
};