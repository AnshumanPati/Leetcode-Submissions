class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int n = nums.size();

        // 0 -> n

        int xorans = 0;

        for(int i=0;i<n;i++){
            xorans ^= nums[i];
            xorans ^= i;
        }

        xorans ^= n;

        return xorans;
        
    }
};