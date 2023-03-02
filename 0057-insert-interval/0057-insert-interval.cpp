class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int i = 0;
        
        // Add all intervals before the new interval
        while (i < intervals.size() && intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i++]);
        }
        
        // Merge overlapping intervals
        while (i < intervals.size() && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        
        // Add the merged interval
        result.push_back(newInterval);
        
        // Add all intervals after the new interval
        while (i < intervals.size()) {
            result.push_back(intervals[i++]);
        }
        
        return result;
    }
};