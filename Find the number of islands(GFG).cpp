class Solution {
  public:
    // Function to find the number of islands.
    void dfs(int i, int j, vector<vector<char>>& grid){
    int n=grid.size();
    int m=grid[0].size();
    if(i<0||j<0)
    return;
    if(i>=n||j>=m){
    return;
    }
    if(grid[i][j]!='1'){
        return;
    }
    grid[i][j]='2';
    // image[i][j]=newcolor;
    dfs(i-1,j,grid);
    dfs(i+1,j,grid);
    dfs(i,j-1,grid);
    dfs(i,j+1,grid);
    dfs(i-1,j-1,grid);
    dfs(i-1,j+1,grid);
    dfs(i+1,j-1,grid);
    dfs(i+1,j+1,grid);

}
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int count=0;
        for(int i=0; i<grid.size(); ++i){
            for(int j=0; j<grid[0].size(); ++j){
                if(grid[i][j]=='1'){
                dfs(i,j,grid);
                count++;
                }
            }
        }
        return count;
    }
};
