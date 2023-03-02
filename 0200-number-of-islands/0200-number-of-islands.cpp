class Solution {

    int islands = 0;
    int rows,cols;
    
    int dirs[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
    
    bool isValid(int x, int y){
        return x>=0 && y>=0 && x<rows && y<cols;
    }
    
    void dfs(vector<vector<char>>& grid, int x, int y){
        grid[x][y] = '0';
        for(auto dir : dirs){
            int x_new = x + dir[0];
            int y_new = y + dir[1];
            if(isValid(x_new,y_new) && grid[x_new][y_new]=='1')
                    dfs(grid,x_new,y_new);
        }       
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
             
        rows = grid.size();
        if(rows==0)
            return 0;
        cols = grid[0].size();
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j] == '1'){
                    islands++;
                    dfs(grid,i,j);
                }
            }
        }
        
        return islands;
        
    }
};