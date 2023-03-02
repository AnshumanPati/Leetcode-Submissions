class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for(int i=0;i<n-2;i++){

            if(i==0 || (i>0 && nums[i]!=nums[i-1])){
                int lo = i+1, hi = n-1, sum = 0 - nums[i];

                while(lo < hi){
                    if(nums[lo] + nums[hi] == sum){
                        vector<int> triplet;
                        triplet.push_back(nums[i]);
                        triplet.push_back(nums[lo]);
                        triplet.push_back(nums[hi]);
                        ans.push_back(triplet);

                        while(lo<hi && nums[lo] == nums[lo+1])
                            lo++;
                        
                        while(lo<hi && nums[hi] == nums[hi-1])
                            hi--;
                        
                        lo++;
                        hi--;
                    }
                    
                    else if(nums[lo] + nums[hi] < sum)
                        lo++;
                    
                    else
                        hi--;
                }
            }
        }
        return ans;
    }
};