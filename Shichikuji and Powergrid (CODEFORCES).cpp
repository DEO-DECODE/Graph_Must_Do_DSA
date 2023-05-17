//Shichikuji and Powergrid (CODEFORCES)
#include <bits/stdc++.h>
using namespace std;
// DSU Code
const int N = 1e5 + 7;
int Parent[N], Size[N];
void make(int vertex)
{
    Parent[vertex] = vertex;
    Size[vertex] = 1;
}
int Find(int vertex)
{
    if (Parent[vertex] == vertex)
        return vertex;
    return Parent[vertex] = Find(Parent[vertex]);
}
void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);
    if (a != b)
    {
        if (Size[a] < Size[b])
            swap(a, b);
        Parent[b] = a;
        Size[a] += Size[b];
    }
}
int main()
{
    int n;
    vector<pair<int, int>> cities(n + 1);
    vector<int> c(n + 1), k(n + 1);
    for (int i = 0; i <= n; ++i)
    {
        int xi, yi;
        cin >> xi >> yi;
        cities[i] = {xi, yi};
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> c[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> k[i];
    }
    set<vector<long long>> st;
    for (int i = 1; i <= n; ++i)
    {
        st.insert({c[i], 0, i});
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            if (i != j)
            {
                int dist = (abs(cities[i].first - cities[j].first) + abs(cities[i].second - cities[j].second));
                long long cost = (k[i] + k[j]) * 1ll * dist;
            }
        }
    }
    auto itr = st.begin();
    int tc = 0;
    vector<int> powerStations;
    vector<pair<int, int>> ans;
    while (itr != st.end())
    {
        int wt = (*itr)[0];
        int city1 = (*itr)[1];
        int city2 = (*itr)[2];
        if (Find(city1) == Find(city2))
            continue;
        else
        {
            if (city1 == 0 || city2 == 0)
                powerStations.push_back(city1 == 0 ? city2 : city1);
            else
            {
                ans.push_back({city1, city2});
            }
        }
    }
}
