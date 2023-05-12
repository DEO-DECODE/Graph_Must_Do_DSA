// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    const int dx[8]={-1,1,-1,1,2,2,-2,-2};
    const int dy[8]={2,2,-2,-2,-1,1,-1,1};
// const int N=1e5+10;
bool isvalid(int x, int y, int N){
    return x>=1&&x<=N&&y>=1&&y<=N;
}
// int bfs(vector<int>&knightPos,vector<int>&TargetPos, int N){
  

// }
	int minStepToReachTarget(vector<int>&knightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	   queue<pair<int, int>> q;
    vector<vector<int>> level(N+1,vector<int>(N+1,-5));
    q.push({knightPos[0],knightPos[1]});
    level[knightPos[0]][knightPos[1]]=0;
    while(!q.empty()){
        pair<int, int> cord=q.front();
        q.pop();
        int X=cord.first;
        int Y=cord.second;
        for(int i=0; i<8; ++i){
            int childx=X+dx[i];
            int childy=Y+dy[i];
            if(!isvalid(childx,childy,N))
            continue;
            if(level[childx][childy]!=-5)
            continue;
            level[childx][childy]=level[X][Y]+1;
            q.push({childx,childy});
        }
        if(level[TargetPos[0]][TargetPos[1]]!=-5)
        {
            break;
        }
    }
    if(level[TargetPos[0]][TargetPos[1]]==-5)
    return -1;
    else
    return level[TargetPos[0]][TargetPos[1]];
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
