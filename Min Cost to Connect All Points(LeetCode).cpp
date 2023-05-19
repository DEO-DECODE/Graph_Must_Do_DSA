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
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int numpoints=points.size();
    vector<pair<int, pair<int, int>>> edges;
    for(int i=0; i<numpoints; ++i){
        for(int j=i+1; j<numpoints; ++j){
            if(i==j) continue;
            int dist=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
            edges.push_back({dist,{i,j}});
        }
    }
    sort(edges.begin(), edges.end());
    for(int i=0; i<numpoints; ++i) make(i);
    int total_cost=0;
    for(auto &edge: edges){
        int cost=edge.first;
        int u=edge.second.first;
        int v=edge.second.second;
        if(Find(u)==Find(v)) continue;
        // This will help in avoiding the condition of putting extra edge.
        Union(u,v);
        total_cost+=cost;
    }
    return total_cost;
    }
};
