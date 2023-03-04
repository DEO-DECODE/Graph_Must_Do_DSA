//Number Of trips (Hackerearth)
#include <bits/stdc++.h>
using namespace std;
/*
1
6 6
1 2 1 2 1 2
5 6
3 4
2 4
3 6
1 4
4 6

1
4
3
1 2 3 4
1 2
1 3
1 4

1
6
2
7 3 9 10 1 4
1 5
2 3

1
5 4
2 4 8 16 32
1 2
1 3
1 4
2 3

*/
void make(int v, vector<int> &parent, vector<int> &sizes)
{
    parent[v] = v; // Adding independent node.
    sizes[v] = 1;
}
int Find(int v, vector<int> &parent)
{
    if (parent[v] == v)
        return v;
    return parent[v] = Find(parent[v], parent);
}
void Union(int a, int b, vector<int> &parent, vector<int> &sizes)
{
    if (Find(a, parent) != Find(b, parent))
    {
        a = Find(a, parent);
        b = Find(b, parent);
        if (sizes[a] < sizes[b])
            swap(a, b);
        parent[b] = a;
        sizes[a] += sizes[b];
    }
}
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> parent(n + 1, 0), sizes(n + 1, 1);
        vector<int> A(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            cin >> A[i];
        }
        vector<pair<long long, pair<long long, long long>>> edges;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = i + 1; j <= n; ++j)
            {
                long long wt = A[i] * A[j];
                edges.push_back({wt, {i, j}});
            }
        }
        sort(edges.begin(), edges.end());
        vector<pair<long long, long long>> RemovedEdges;
        for (int i = 0; i < m; ++i)
        {
            int x, y;
            cin >> x >> y;
            RemovedEdges.push_back({x, y});
        }
        for (int i = 1; i <= n; ++i)
            make(i, parent, sizes);
        int numEdges = 0;
        int totalCost = 0;
        for (auto &edge : edges)
        {
            long long wt = edge.first;
            int u = edge.second.first, v = edge.second.second;
            if (Find(u, parent) == Find(v, parent))
            {
                continue;
            }
            pair<long long, long long> pr = {u, v};
            auto itr = find(RemovedEdges.begin(), RemovedEdges.end(), pr);
            if (itr == RemovedEdges.end())
            {
                // cout<<u<<" - "<<v<<endl;
                Union(u, v, parent, sizes);
                totalCost += wt;
                numEdges++;
            }
            if (numEdges == n - 1)
                break;
        }
        if (numEdges == n - 1)
            cout << totalCost << endl;
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}
