class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        long long lo = 1;
        long long hi = 1000000000000;

        while(lo<=hi){
            long long mid = lo + (hi-lo)/2;

            if(canEat(piles, mid, h))
                hi = mid-1;
            
            else
                lo = mid+1;
        }
        return lo;
    }

    bool canEat(vector<int> &piles, long long k, long long h){

        long long hrs = 0;

        for(int i=0;i<piles.size();i++){
            long long div = piles[i]/k;
            hrs += div;
            if(piles[i]%k != 0)
                hrs++;
        }
        return hrs <= h;
    }
};