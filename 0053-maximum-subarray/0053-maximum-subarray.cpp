class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int is_all_negative = 0;

        int n = nums.size();

        for(int i=0;i<n;i++){
            if(nums[i] >= 0){
                is_all_negative = 1;
                break;
            }
        }

        if(is_all_negative == 0){
            int maxi = nums[0];
            for(int i=1;i<n;i++){
                maxi = max(maxi, nums[i]);
            }
            return maxi;
        }
        else{
        int sum = 0;
        int maxsum = 0;
        for(int i=0;i<n;i++){
            if(nums[i] + sum < 0){
                sum = 0;
            }
            else
                sum += nums[i];
            maxsum = max(sum, maxsum);
        }
        return maxsum;
        }
    }
};