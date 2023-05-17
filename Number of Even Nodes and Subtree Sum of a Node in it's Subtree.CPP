//Number of Even Nodes and Subtree Sum of a Node in it's Subtree 
#include <bits/stdc++.h>
using namespace std;
// DSU Code
const int N = 1e5 + 7;
int subtreeSum[N], evenCount[N];
void dfs(int vertex, int parent, vector<int> adj[])
{
    if (vertex % 2 == 0)
        evenCount[vertex] += 1;
    subtreeSum[vertex] += vertex;
    for (auto child : adj[vertex])
    {
        if (child == parent)
            continue;
        dfs(child, vertex, adj);
        evenCount[vertex] += evenCount[child];
        subtreeSum[vertex] += subtreeSum[child];
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> adj[n + 1];
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    dfs(1,-1, adj);
    for(int i=1; i<=n; ++i){
        cout<<evenCount[i]<<" "<<subtreeSum[i]<<endl;
    }
}
