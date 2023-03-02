class Solution {

    int robHelper(vector<int>& nums, int start, int end) {
        int n = end - start + 1;
        if (n == 1) 
            return nums[start];
        if (n == 2) 
            return max(nums[start], nums[end]);
        
        vector<int> dp(n, 0);
        dp[0] = nums[start];
        dp[1] = max(nums[start], nums[start+1]);

        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i-2]+nums[start+i], dp[i-1]);
        }
        return dp[n-1];
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) 
            return nums[0];
        return max(robHelper(nums, 0, n-2), robHelper(nums, 1, n-1));
    }
};