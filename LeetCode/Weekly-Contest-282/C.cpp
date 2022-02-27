class Solution {
    
    typedef long long LL;
    
public:
    LL minimumTime(vector<int>& time, int totalTrips) {
        LL left = 1ll, right = 1e14 + 10;
        while (left <= right) {
            LL mid = (left + right) >> 1;
            LL cnt = 0;
            for (int t : time)
                cnt += mid / t;
            if (cnt >= totalTrips)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return left;
    }
};