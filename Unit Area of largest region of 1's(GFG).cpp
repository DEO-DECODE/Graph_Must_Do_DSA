class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    void dfs(vector<vector<int>>& grid,int row, int col, int &ans){
        int m=grid.size();
        int n=grid[0].size();
        if(row>=m||row<0||col>=n||col<0||grid[row][col]==2||grid[row][col]==0)
        return;
        grid[row][col]=2;
        ans+=1;
        // cout<<row<<" "<<col<<endl;
        dfs(grid,row-1,col,ans);
        dfs(grid,row+1,col,ans);
        dfs(grid,row,col-1,ans);
        dfs(grid,row,col+1,ans);
        dfs(grid,row+1,col+1,ans);
        dfs(grid,row+1,col-1,ans);
        dfs(grid,row-1,col-1,ans);
        dfs(grid,row-1,col+1,ans);
        
}
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
    int m=grid.size();
    int n=grid[0].size();
    int maxm=0;
    for(int i=0; i<m; ++i){
        
        for(int j=0; j<n; ++j){

            if(grid[i][j]==1){
                int ans=0;
                dfs(grid, i,j, ans);
                maxm=max(maxm,ans);           
            }
        }
    }
    return maxm;
    }
};
