#include <bits/stdc++.h>
using namespace std;
// Max Area of Island(LeetCode)
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
void dfs(int r, int c, vector<vector<int>> &grid, int &count)
{
    int n = grid.size(), m = grid[0].size();
    if (r < 0 || r >= n || c < 0 || c >= m)
        return;
    if (grid[r][c] == -1||grid[r][c]==0)
        return;
    grid[r][c] = -1;
    count++;
    for (int mv = 0; mv < 4; ++mv)
    {
        int childx = r + dx[mv], childy = c + dy[mv];
        dfs(childx, childy, grid, count);
    }
}
int maxAreaOfIsland(vector<vector<int>> &grid)
{
    int n = grid.size(), m = grid[0].size(), ans = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (grid[i][j] == 1)
            {
                int count = 0;
                dfs(i, j, grid, count);
                // cout << i << " " << j << " " << count << endl;
                // ans += count;
                ans=max(ans, count);
            }
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> grid = {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}, {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0}, {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
    cout << maxAreaOfIsland(grid);
}
