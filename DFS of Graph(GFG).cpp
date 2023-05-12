class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> cc;
    
    void dfs(int vertex,vector<int>& vis ,vector<int> adj[]){
    // cout<<"Vertex : "<<vertex<<endl;
    vis[vertex]=1;
    cc.push_back(vertex);
    for(int child: adj[vertex]){
        // cout<<"Parent : "<<vertex<<" Child : "<<child<<endl;
        if(vis[child])
        continue;
        dfs(child,vis,adj);
    }

    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V,0);
        dfs(0,vis,adj);
        return cc;
    }
};
