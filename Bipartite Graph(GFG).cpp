// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
int flag=0;
    void dfsbp(int src, int par, int col, vector<int> adj[], vector<int> &vis){
        vis[src]=col;
        for(auto x: adj[src]){
            if(vis[x]==-1){
                // col=col^1;
                dfsbp(x,src,col^1,adj,vis);
            }
            else if(x!=par&&vis[src]==vis[x]){
                flag=1;
                break;
            }
        }
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    int fl2=0;
	    vector<int> vis(V+1,-1);
	    for(int i=0; i<V; ++i){
	        if(vis[i]!=-1) continue;
	        int col=0;
	        dfsbp(i,0,col,adj,vis);
	        if(flag){
	            fl2=1;
	            break;
	        }
	    }
		// cout<<"\n\n";
		// for(int i=0; i<V; ++i)
		// cout<<i<<" "<<vis[i]<<endl;
	    if(fl2){
	        return false;
	    }
	    return true;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends
