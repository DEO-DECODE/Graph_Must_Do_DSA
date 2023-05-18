// Longest Path With Different Adjacent Characters(LeetCode)
#include <bits/stdc++.h>
using namespace std;
void dfs(int vertex, int par, vector<int> adj[], vector<int> &preComp, string &s, int &ans)
{
    preComp[vertex] = 1;
    for (auto child : adj[vertex])
    {
        if (child != par)
        {
            dfs(child, vertex, adj, preComp, s, ans);
            ans = max(ans, preComp[vertex] + preComp[child]);
            preComp[vertex] = max(preComp[vertex], preComp[child] + 1);
        }
    }
}
int longestPath(vector<int> &parent, string s)
{
    int n = parent.size();
    vector<int> adj[n + 1];
    vector<int> preComp(n + 1, 0);
    for (int i = 1; i < n; ++i)
    {
        adj[parent[i]].push_back(i);
        // adj[i].push_back(parent[i]);
    }
    int ans = 0;
    dfs(0, -1, adj, preComp, s, ans);
    for (int i = 0; i < n; ++i)
    {
        cout << i << " - " << preComp[i] << endl;
    }
    return ans;
}
int main()
{
    vector<int> parent = {-1, 0, 0, 0, 3, 3, 3, 2, 2, 8, 1, 1};
    string s = "xyzxaaammmzz";
    cout << longestPath(parent, s);
}
