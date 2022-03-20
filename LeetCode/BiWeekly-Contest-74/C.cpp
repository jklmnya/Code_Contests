class Solution {
public:
	int halveArray(vector<int>& nums) {
		double sum = 0ll;
		for (int num : nums)
			sum += num;
		priority_queue<double> pq;
		for (int num : nums)
			pq.emplace((double)num);
		int res = 0;
		double now = sum;
		sum /= 2;
		while (now > sum) {
			double d = pq.top();
			pq.pop();
			now -= d / 2;
			if (d > 0)
				pq.emplace(d / 2);
			++res;
		}
		return res;
	}
};