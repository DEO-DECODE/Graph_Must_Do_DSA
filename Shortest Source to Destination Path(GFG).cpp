// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:

// bool isvalid2(int x, int y, vector<vector<int>> A){
//     if(A[x][y]==0)
//     return false;
//     return true;
// }
// bool isvalid(int x, int y, int N, int M){
    
//     return x>=0&&y>=0&&x<N&&y<M;
// }
int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
   if(A[0][0]==0 || A[X][Y]==0){
            return -1;
    }
    // int INF=1e9+10;
    // vector<vector<int>> level(A.size(),vector<int>(A[0].size(),INF)); 
    int ans=0;
    queue<pair<int, int>> q;
    q.push({0,0});
    // level[0][0]=0;
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    while(!q.empty()){
        int s=q.size();
        for(int z=0; z<s; z++){
        pair<int, int> curr=q.front();
        int x = curr.first,y=curr.second;
        if(x==X and y==Y){
            return ans;
        }
        q.pop();
        for(int i=0; i<4; ++i){
            int childx=x+dx[i];
            int childy=y+dy[i];
        if( x+dx[i]>=0 and y+dy[i]>=0 and x+dx[i]<N and y+dy[i]<M and A[childx][childy]==1){
            q.push({childx,childy});
            A[childx][childy]=0;
        }
        }
        }
        ans++;
    }
   
    return -1;

}
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}  // } Driver Code Ends
