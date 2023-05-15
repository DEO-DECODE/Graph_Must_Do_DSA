

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool reach=false;
    void dfs(vector<vector<int>> &grid, int row, int col){
        int m=grid.size();
        int n=grid[0].size();
        if(row>=m||row<0||col>=n||col<0)
        return;
        if(grid[row][col]==0)
        return;
        if(grid[row][col]==2)
        {
            reach=true;
            return;
        }
        grid[row][col]=0;
        dfs(grid,row-1,col);
        dfs(grid,row+1,col);
        dfs(grid,row,col-1);
        dfs(grid,row,col+1);
        
    }
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
         int m=grid.size();
        int n=grid[0].size();
        for(int i=0; i<m; ++i){
            bool lp=false;
            for(int j=0; j<n; j++){
                
                if(grid[i][j]==1){
                    dfs(grid,i,j);
                    lp=true;
                    break;
                }
            }
            if(lp){
                break;
            }
        }
        return reach;
    }
};
