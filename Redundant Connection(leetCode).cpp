const int N = 1e5; // 9:05
int parent[N];
int Size[N];
class Solution {
public:
   void make(int v)
{
    parent[v] = v;
    Size[v] = 1;
}
int Find(int v)
{
    if (parent[v] == v)
    {
        return v;
    }
    return parent[v] = Find(parent[v]);
}
void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);
    if (a != b)
    {
        if (Size[a] < Size[b])
        {
            swap(a, b);
        }
        parent[b] = a;
        Size[a] += Size[b];
    }
}
    vector<int> findRedundantConnection(vector<vector<int>> & edges)
    {
        int n = edges.size();
        for (int i = 1; i <= n; ++i)
        {
            make(i);
        }
        vector<int> finalAns;
        for (int i = 0; i < edges.size(); ++i)
        {
            int x = edges[i][0], y = edges[i][1];
            if (Find(x) == Find(y))
            {
                finalAns = {x, y};
            }
            else{
                Union(x,y);
            }
        }

        return finalAns;
    }
};
