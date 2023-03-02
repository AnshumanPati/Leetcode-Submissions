class Solution {
  
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int lo = 0, hi = n-1;
        int mid = 0;

        while(mid <= hi){
            if(nums[mid] == 0){
                swap(nums[mid++], nums[lo++]);
            }
            else if(nums[mid] == 2){
                swap(nums[mid], nums[hi--]);
            }
            else
                mid++;
        }
    }
};