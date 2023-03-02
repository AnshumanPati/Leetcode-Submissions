class Solution {

public:
    int uniquePaths(int m, int n) {

        int ans = 0;

        int grid[m][n];

        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                grid[i][j] = 0;

        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){

                if(i==m-1 || j==n-1)
                    grid[i][j] = 1;

                else{
                    grid[i][j] = grid[i+1][j] + grid[i][j+1];
                }    

            }
        }
        return grid[0][0];        
    }
};