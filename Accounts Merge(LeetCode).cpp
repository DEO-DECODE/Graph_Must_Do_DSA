#include <bits/stdc++.h>
using namespace std;
// Accounts Merge(LeetCode)
int Find(int v, vector<int> &parent)
{
    if (parent[v] == v)
        return v;
    return parent[v] = Find(parent[v], parent);
}
vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
{
    int n = accounts.size();
    unordered_map<string, int> mailBox;
    vector<int> parent(n, 0);
    for (int i = 0; i < n; ++i)
    {
        parent[i] = i;
        for (int j = 1; j < accounts[i].size(); ++j)
        {
            if (mailBox.find(accounts[i][j]) != mailBox.end())
            {
                int f1 = Find(i, parent);
                int f2 = Find(mailBox[accounts[i][j]], parent);
                parent[f1] = f2;
            }
            else
            {
                mailBox[accounts[i][j]] = parent[i];
            }
        }
    }
    unordered_map<int, vector<string>> combinedMail;
    for (auto it : mailBox)
    {
        int f = Find(it.second, parent);
        combinedMail[f].push_back(it.first);
    }
    vector<vector<string>> finalAns;
    for (auto it : combinedMail)
    {
        sort(it.second.begin(), it.second.end());
        vector<string> temp = {accounts[it.first][0]};
        for (auto str : it.second)
        {
            temp.push_back(str);
        }
        finalAns.push_back(temp);
    }
    return finalAns;
}
