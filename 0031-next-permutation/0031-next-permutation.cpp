class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size();
        int inflectionpoint = nums[n-1];

        for(int i=n-1;i>=1;i--){
            if(nums[i-1]<nums[i]){
                inflectionpoint = i;
                break;
            }
        }

        int to_swap = inflectionpoint - 1;
        int swap_with = n-1;

        for(int i=n-1;i>=0;i--){
            if(nums[i]>nums[to_swap]){
                swap_with = i;
                break;
            }
        }

        int tmp = nums[to_swap];
        nums[to_swap] = nums[swap_with];
        nums[swap_with] = tmp;

        sort(nums.begin()+inflectionpoint,nums.end());

    }
};