class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_map<int, char> mp;
  mp[1] = 'A', mp[2] = 'C', mp[3] = 'G', mp[4] = 'T';
  queue<string> q;
  map<string, int> vis;
  vis[startGene] = 1;
  q.push(startGene);
  int steps = 0;
  while (q.size() > 0)
  {
    int sz = q.size();
    while (sz--)
    {
      auto curStr = q.front();
      q.pop();
      if (curStr == endGene)
        return steps;
      for (int ind = 0; ind < curStr.size(); ++ind)
      {
        char temp = curStr[ind];
        for (int i = 1; i <= 4; ++i)
        {
          curStr[ind] = mp[i];
          if (find(bank.begin(), bank.end(), curStr) != bank.end() && vis[curStr] == 0)
          {
            q.push(curStr);
            vis[curStr] = 1;
          }
          curStr[ind] = temp;
        }
      }
    }
    steps++;
  }
  return -1;
    }
};
