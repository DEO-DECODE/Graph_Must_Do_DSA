class Solution {
public:
    bool check(int vertex, vector<vector<int>> &graph, vector<int> &pathVisited, vector<int> &safeNodes, vector<int> &visited)
{
	visited[vertex] = 1;
	pathVisited[vertex] = 1;
	safeNodes[vertex] = 0;
	for (auto child : graph[vertex])
	{
		if (visited[child] == 0)
		{
			if (check(child, graph, pathVisited, safeNodes, visited))
			{
				safeNodes[vertex] = 0;
				return true;
			}
		}
		else if (pathVisited[child] == 1)
		{
			return true;
		}
	}
	pathVisited[vertex] = 0;
	safeNodes[vertex]=1;
	return false;
}
vector<int> eventualSafeNodes(vector<vector<int>> &graph)
{
	int n = graph.size();
	vector<int> pahVisited(n, 0), visited(n, 0), safeNodes(n, 0);
	for (int i = 0; i < n; ++i)
	{
		if (visited[i] == 0)
		{
			check(i, graph, pahVisited, safeNodes, visited);
		}
	}
	vector<int> ans;
	for(int i=0; i<n; ++i){
		if(safeNodes[i]==1){
			ans.push_back(i);
		}
	}
	return ans;
}
};
