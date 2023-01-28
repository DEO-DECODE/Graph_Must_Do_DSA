//  Roads not only in Berland(HackerEarth)
/*
-There are total n cities and n-1 edges , It clearly means that there are more than one components in
the garaph.
-DSU can be used to solve this problem involving multiple connected components 
*/

#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
int parent[N];
int sizes[N];
void make(int v){
    parent[v]=v;//Adding independent node.
    sizes[v]=1;
}
int Find(int v){
    if(parent[v]==v) return v;
    return parent[v]=Find(parent[v]);
}
void Union(int a, int b){
    if(Find(a)!=Find(b)){
        a=Find(a);
        b=Find(b);
        if(sizes[a]<sizes[b])
        swap(a,b);
        parent[b]=a;
        sizes[a]+=sizes[b];
    }
}
int main(){
    int n;
    cin>>n;
    vector<pair<int, int>> newp, extra;
    for(int i=1; i<=n; ++i)
    make(i);
    for(int i=0; i<n-1; ++i)
    {
        int u,v;
        cin>>u>>v;
        if(Find(u)==Find(v)){
            extra.push_back({u,v});
        }
        else{
            Union(u,v);
        }
    }
    for(int i=1; i<=n; ++i){
        for(int j=i+1; j<=n; ++j){
            if(Find(i)==Find(j)) continue;
            else{
                newp.push_back({i,j});
                Union(i,j);
            }
        }
    }
    return 0;
}
