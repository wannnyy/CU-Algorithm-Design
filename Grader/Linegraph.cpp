#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj(100000);
vector<bool> visited(100000, false);

void dfs(int start, int &maxDeg, int &nodeCount, int &edgeCount)
{
    stack<int> s;
    s.push(start);
    visited[start] = true;

    while (!s.empty())
    {
        int u = s.top();
        s.pop();

        nodeCount++;
        int deg = adj[u].size();
        maxDeg = max(maxDeg, deg);
        edgeCount += deg;

        for (auto x : adj[u])
        {
            if (!visited[x])
            {
                visited[x] = true;
                s.push(x);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int v, e;
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int ans = 0;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            int maxDeg = 0, nodeCount = 0, edgeCount = 0;
            dfs(i, maxDeg, nodeCount, edgeCount);

            edgeCount /= 2;
            if (nodeCount == 1)
            {
                ans++;
            }
            else
            {
                if (edgeCount == nodeCount - 1 && maxDeg <= 2)
                {
                    ans++;
                }
            }
        }
    }
    cout << ans;

    return 0;
}