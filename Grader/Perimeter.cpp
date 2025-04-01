#include <bits/stdc++.h>

using namespace std;
int n, e, k;

int main()
{
    cin >> n >> e >> k;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        // Undirected graph
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<int> q;
    vector<int> dist(n + 1, -1);
    q.push(0);
    dist[0] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (auto x : adj[u])
        {
            if (dist[x] <= k)
            {
                if (dist[x] == -1)
                {
                    dist[x] = dist[u] + 1;
                    q.push(x);
                }
            }
        }
    }
    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == k)
        {
            answer++;
        }
    }

    cout << answer << "\n";
    return 0;
}