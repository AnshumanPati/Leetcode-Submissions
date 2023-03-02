class Solution {

    int findMaxLis(vector<int>& nums, vector<vector<int>>& t, int idx, int prev){
        
        if(idx == nums.size()){
            return 0;
        }

        if(t[idx][prev+1] != -1)
            return t[idx][prev+1];

        int len = 0 + findMaxLis(nums, t, idx+1, prev);

        if(prev == -1 || nums[idx] > nums[prev]){
            len = max(len, 1 + findMaxLis(nums, t, idx+1, idx));
        }

        return t[idx][prev+1] = len;

    }

public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();

        vector<vector<int>> t(n, vector<int>(n+1, -1));
        
        return findMaxLis(nums, t, 0, -1);
    }
};