//User function Template for C++

class Solution {
  public:
  void dfs(int vertex,vector<int> &vis, vector<int> graph2[]){
    vis[vertex]=1;
    for(int child: graph2[vertex]){
        if(vis[child])
        continue;
        dfs(child,vis,graph2);
       
    }
}
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int> lis[V+1];
        int row=adj.size();
        int col=adj[0].size();
        for(int i=0; i<row; ++i){
            for(int j=0; j<col; ++j){
                if(adj[i][j]==1){
                    lis[i].push_back(j);
                }
            }
        }
        vector<int> vis(V+1,0);
        int ans=0;
        for(int i=0; i<V; ++i){
            if(vis[i])continue;  
            dfs(i,vis,lis);
            ans++;
        }
        return ans;
    }
};
