class Solution {

    int binarysearch(vector<int>& nums, int left, int right, int target, int flag){

        if(flag == 0){
            while(left <= right){
                int mid = left + (right - left)/2;
                if(nums[mid] == target)
                    return mid;
                else if(nums[mid] < target){
                    left = mid+1;
                }
                else{
                    right = mid-1;
                }
            }
        }
        else if(flag == 1){
            while(left <= right){
                int mid = left + (right - left)/2;
                if(nums[mid] == target)
                    return mid;
                else if(nums[mid] > target){
                    left = mid+1;
                }
                else{
                    right = mid-1;
                }
            }
        }

        return -1;
    }

public:
    int search(vector<int>& nums, int target) {
        
        int pivot = -1;

        int n = nums.size();

        if(n == 1){
            return target == nums[0] ? 0 : -1;
        }

        int lo = 0, hi = nums.size()-1;

        while(lo <= hi){
            int mid = lo + (hi-lo)/2;

            if((mid>0 && mid<n-1 && nums[mid]<nums[mid+1] && nums[mid]<nums[mid-1])
            || (mid==n-1 && nums[mid]<nums[mid-1])){
                pivot = mid;
                break;
            }

            else if(nums[lo]<=nums[mid] && nums[mid]>=nums[hi])
                lo = mid+1;
            
            else
                hi = mid-1;
        }

        if(pivot == -1){
            return binarysearch(nums, 0, n-1, target, nums[0]<nums[n-1]?0:1);
        }

        int idx1 = binarysearch(nums, 0, pivot-1, target, 0);
        int idx2 = binarysearch(nums, pivot, n-1, target, 0);
        
        if(idx1 == -1)
            return idx2;
        
        return idx1;

    }
};