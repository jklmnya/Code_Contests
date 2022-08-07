class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        
        if (n == 2)
            return nums[0] == nums[1];    
        
        bool f[n + 1][3];
        memset(f, 0, sizeof f);
        if (nums[0] == nums[1])
            f[2][0] = true;
        if (nums[0] == nums[1] && nums[1] == nums[2])
            f[3][1] = true;
        if (nums[0] == nums[1] - 1 && nums[1] == nums[2] - 1)
            f[3][2] = true;
            
        for (int i = 4;i<=n;++i) {
            f[i][0] = (nums[i - 1] == nums[i - 2]) && (f[i - 2][0] || f[i - 2][1] || f[i - 2][2]);
            f[i][1] = (nums[i - 1] == nums[i - 2] && nums[i - 2] == nums[i - 3]) && (f[i - 3][0] || f[i - 3][1] || f[i - 3][2]);
            f[i][2] = (nums[i - 1] == nums[i - 2] + 1 && nums[i - 2] == nums[i - 3] + 1) && (f[i - 3][0] || f[i - 3][1] || f[i - 3][2]);
        }
        
        return f[n][0] || f[n][1] || f[n][2];
    }
};