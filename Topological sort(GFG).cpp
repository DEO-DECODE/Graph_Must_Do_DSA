// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int n, vector<int> adj[]) 
	{
	    // code here
	    
    vector<int> indeg(n,0);
    for(int i=0; i<n; ++i){
        for(auto val: adj[i]){
            indeg[val]++;
        }
    }
    queue<int> q;
    for(int i=0; i<n; ++i){
        if(indeg[i]==0){
            q.push(i);
        }
    }
    int numnodes=0;
    vector<int> ans;
    while(!q.empty()){
        int currnode=q.front();
        ans.push_back(currnode);
        q.pop();
        numnodes++;
        for(auto child: adj[currnode]){
            indeg[child]--;
            if(indeg[child]==0){
                q.push(child);
            }
        }
    }
    
    return ans;
	}
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends
