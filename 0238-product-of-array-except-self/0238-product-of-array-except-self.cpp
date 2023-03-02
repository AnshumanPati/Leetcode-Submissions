class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans;
        int right = 1;
        ans.push_back(1);
        
        for(int i=1;i<n;i++){
            ans.push_back(ans[i-1]*nums[i-1]);
        }
        
        for(int i=n-1;i>=0;i--){
            ans[i] = ans[i]*right;
            right*=nums[i];
        }
        
        return ans;
        
        
    }
};