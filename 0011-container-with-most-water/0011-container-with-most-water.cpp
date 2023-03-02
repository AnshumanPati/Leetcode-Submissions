class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int begin = 0, end = n-1;
        int maxarea = 0;
        
        while(begin<=end){
            int area = (end-begin)*min(height[begin],height[end]);
            maxarea = max(maxarea,area);
            if(height[begin]<=height[end])
                begin++;
            else
                end--;
        }
        return maxarea;
    }
};