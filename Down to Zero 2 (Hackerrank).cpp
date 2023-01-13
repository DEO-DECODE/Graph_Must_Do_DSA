#include <bits/stdc++.h>
using namespace std;
int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        int n;
        cin >> n;
        queue<int> q;
        q.push(n);
        vector<int> vis(n+1, 0);
        vis[n] = 1;
        vector<int> level(n+1, 0);
        // cout << "\n\n";
        bool found = false;
        while (!q.empty())
        {
            int sz = q.size();
            for (int k = 0; k < sz; ++k)
            {
                int currv = q.front();
                q.pop();
                // cout << currv << " ";
                if (currv == 0)
                {
                    found=true;
                    break;
                }
                if (!vis[currv - 1])
                {
                    q.push(currv - 1);
                    vis[currv - 1] = 1;
                    level[currv-1]=level[currv]+1;
                }
                for (int i = 2; i*i <= currv; ++i)
                {
                    if (currv % i == 0)
                    {
                        int qt = currv / i;
                        int val = max(qt, i);
                        if (!vis[val])
                        {
                            q.push(val);
                            vis[val] = 1;
                            level[val] = level[currv] + 1;
                        }
                    }
                }
                
            }
            if(found) break;
            // cout << endl;
        }
        cout<<level[0]<<endl;
    }
}
