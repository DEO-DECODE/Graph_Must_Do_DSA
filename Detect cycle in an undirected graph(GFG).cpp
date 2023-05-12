class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(int vertex, int par,vector<int> &vis,vector<int> adj[]){
    // cout<<"Vertex : "<<vertex<<endl;
    vis[vertex]=1;
    // cc.push_back(vertex);
    bool isloop=false;
    for(int child: adj[vertex]){
        // cout<<"Parent : "<<vertex<<" Child : "<<child<<endl;
        if(vis[child]&&child==par)
        continue;
        if(vis[child])
        return true;
        isloop|=dfs(child,vertex,vis,adj);
    }
    return isloop;
}
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V+1);
        bool islp=false;
        for(int i=0; i<V; ++i){
            if(vis[i])
            continue;
            if(dfs(i,-1,vis,adj)){
                islp =true;
                break;
            }
        }
        // dfs(0,-1,vis,adj);
        return islp;
    }
};
