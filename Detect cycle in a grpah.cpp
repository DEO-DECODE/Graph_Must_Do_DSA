#include <bits/stdc++.h>
using namespace std;
// detect cycle in a grpah
bool dfs(int vertex, int parent, vector<int> &vis, vector<vector<int>> &graph)
{
    vis[vertex] = 1;
    for (auto child : graph[vertex])
    {
        if (vis[child] == 0)
        {
            if (dfs(child, vertex, vis, graph))
                return true;
        }
        else if (vis[child] && child != parent)
        {
            return true;
        }
    }
    return false;
}
bool isCycle(int V, vector<vector<int>> &graph)
{
    vector<int> vis(V, 0);
    // for graph with connected components
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, -1, vis, graph) == true)
                return true;
        }
    }
    return false;
}
