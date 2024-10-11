class Solution
{
public:
    bool dfs(vector<vector<int>> &graph, vector<bool> &vis, vector<bool> &term, vector<bool> &cycle, int src)
    {
        vis[src] = 1;
        term[src] = 1;
        for (auto it : graph[src])
        {
            if (!vis[it])
            {
                if (dfs(graph, vis, term, cycle, it))
                {
                    cycle[src] = 1;
                    return 1;
                }
            }
            else if (term[it])
            {
                cycle[src] = 1;
                return 1;
            }
        }
        term[src] = 0;
        return 0;
    }
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<bool> vis(n, 0), term(n, 0), cycle(n, 0);
        vector<int> results;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs(graph, vis, term, cycle, i);
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (!cycle[i])
            {
                results.push_back(i);
            }
        }

        return results;
    }
};