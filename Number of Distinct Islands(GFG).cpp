// Number of Distinct Islands(GFG)
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    void dfs(int r, int c, vector<vector<int>> &vis, vector<vector<int>> &grid, int &r0, int &c0, vector<pair<int, int>> &track)
    {
        vis[r][c] = 1;
        track.push_back({r - r0, c - c0});
        for (int change = 0; change < 4; ++change)
        {
            int childx = r + dx[change];
            int childy = c + dy[change];
            if (childx < 0 || childx >= grid.size() || childy < 0 || childy >= grid[0].size())
            {
                continue;
            }
            if (vis[childx][childy] == 1)
                continue;
            if (grid[childx][childy] == 0)
                continue;
            dfs(childx, childy, vis, grid, r0, c0, track);
        }
    }
    int countDistinctIslands(vector<vector<int>> &grid)
    {
        // code here
        set<vector<pair<int, int>>> answer;
        /*
        Agar do islands identical honge , to unke dfs call v similar honge and saath ki saath , row change and column change v.
        */
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (grid[i][j] == 1 && vis[i][j] == 0)
                {
                    vector<pair<int, int>> track;
                    dfs(i, j, vis, grid, i, j, track);
                    answer.insert(track);
                }
            }
        }
        return answer.size();
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends
