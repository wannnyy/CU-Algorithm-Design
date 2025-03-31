#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> c(n);
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }

    vector<vector<int>> adj(n);
    vector<int> indeg(n, 0);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indeg[v]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indeg[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> topo_order;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        topo_order.push_back(u);
        for (auto &v : adj[u])
        {
            indeg[v]--;
            if (indeg[v] == 0)
            {
                q.push(v);
            }
        }
    }

    vector<int> dp(n);
    for (int i = 0; i < n; i++)
    {
        dp[i] = c[i];
    }

    for (int u : topo_order)
    {
        for (int v : adj[u])
        {
            dp[v] = min(dp[v], dp[u]);
        }
    }

    int max_diff = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int diff = c[i] - dp[i];
        max_diff = max(max_diff, diff);
    }

    cout << max_diff;

    return 0;
}