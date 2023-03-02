class Solution {
public:
    int findMin(vector<int>& a) {
        int n = a.size();
        int lo = 0, hi = n-1;
        
        while(lo<=hi){
            int mid = lo+((hi-lo)/2);
            if(a[lo]<=a[mid] && a[mid]<=a[hi])
                return a[lo];
            else if(a[lo]>=a[mid] && a[mid]>=a[lo])
                return a[hi];
            else if(a[mid]<=a[lo] && a[mid]<=a[hi] && mid+1==hi & mid-1==lo)
                return a[mid];
            else if(a[mid]>=a[hi] && a[mid]>=a[lo])
                lo++;
            else if(a[mid]<=a[lo] && a[mid]<=a[hi])
                hi--;
        }
        return -1;
    }
};