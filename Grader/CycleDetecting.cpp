#include <bits/stdc++.h>

using namespace std;

bool dfs(int node, int parent, vector<vector<int>> &graph, vector<bool> &visited)
{
    visited[node] = true;
    for (int neighbor : graph[node])
    {
        if (!visited[neighbor])
        {
            if (dfs(neighbor, node, graph, visited))
            {
                return true;
            }
        }
        else if (neighbor != parent)
        {
            return true;
        }
    }
    return false;
}

bool hasCycle(int n, vector<vector<int>> &graph)
{
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (dfs(i, -1, graph, visited))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n, e;
        cin >> n >> e;
        vector<vector<int>> graph(n, vector<int>(0));
        for (int i = 0; i < e; i++)
        {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        if (hasCycle(n, graph))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}