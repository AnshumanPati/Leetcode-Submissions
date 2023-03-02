class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        int n = intervals.size();

        vector<vector<int>> soln;
        sort(intervals.begin(),intervals.end());
        soln.push_back(intervals[0]);

        for(int i=1;i<n;i++){
            int li = intervals[i][0];
            int ri = intervals[i][1];

            if(li <= soln[soln.size()-1][1]){
                soln[soln.size()-1][1] = max(soln[soln.size()-1][1], ri);
            }
            else
                soln.push_back(intervals[i]);
        }
        return soln;
    }
};