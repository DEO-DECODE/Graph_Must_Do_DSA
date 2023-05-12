class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> ans;
    void bfs(int source, vector<int> adj[], vector<int> level){
    queue<int> q;
    q.push(source);
    while(!q.empty()){
        int frnt=q.front();
        q.pop();
        ans.push_back(frnt);
        for(auto child: adj[frnt]){
            if(level[child])continue;
            // vis[child]=1;
            level[child]=level[frnt]+1;
            q.push(child);
        }
    }
}
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> level(V+5,0);
        level[0]=0;
        bfs(0,adj,level);
        return ans;
    }
};
