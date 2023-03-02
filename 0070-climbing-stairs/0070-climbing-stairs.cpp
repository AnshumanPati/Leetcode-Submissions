class Solution {
public:
    int climbStairs(int n) {
        int ways_to_reach[n+1];

        if(n <= 2){
            return n;
        }

        ways_to_reach[n] = 1;
        ways_to_reach[n-1] = 1;

        for(int i=n-2;i>=0;i--){
            ways_to_reach[i] = ways_to_reach[i+1] + ways_to_reach[i+2];
        }
        
        return ways_to_reach[0];
    }
};