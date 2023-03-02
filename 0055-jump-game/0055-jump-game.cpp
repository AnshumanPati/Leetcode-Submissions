class Solution {
  
public:
    bool canJump(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> can_reach_n(n,0);
        can_reach_n[n-1] = 1;
        
        for(int i=n-2;i>=0;i--){
            int max_possible_jump = min(i+nums[i],n-1);
            for(int j=i+1;j<=max_possible_jump;j++){
                if(can_reach_n[j] == 1){
                    can_reach_n[i] = 1;
                    break;
                }
            }
        }    
        return can_reach_n[0]==1;        
    }
};