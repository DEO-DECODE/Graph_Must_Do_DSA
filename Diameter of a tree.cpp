// Diameter of a tree
#include <bits/stdc++.h>
using namespace std;
// DSU Code
const int N = 1e5 + 7;
int depth[N];
void dfs(int vertex, int parent, vector<int> adj[])
{

    for (auto child : adj[vertex])
    {
        if (child == parent)
            continue;
        depth[child] = depth[vertex] + 1;
        dfs(child, vertex, adj);
    }
}
int main()
{
    // Run a DFS with respect to any node and then find the farthest node and then run dfs with respect to that node and tehn find the maximum depth.
    int n;
    cin >> n;
    vector<int> adj[n + 1];
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    int maxDepth = 1;
    int maxDistNode = -1;
    dfs(1, -1, adj);
    for (int i = 1; i <= n; ++i)
    {
        if (maxDepth < depth[i])
        {
            maxDepth = depth[i];
            maxDistNode = i;
        }
    }
    dfs(maxDistNode, -1, adj);
    maxDistNode = -1;
    maxDepth = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (maxDepth < depth[i])
        {
            maxDepth = depth[i];
        }
    }
    cout << maxDepth;
}
