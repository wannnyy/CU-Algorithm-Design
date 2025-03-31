#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, e, k;
    cin >> n >> e >> k;

    // We have vertices labeled 0..n
    // 0 is the base, and 1..n are the possible outposts
    vector<vector<int>> adj(n + 1);

    // Read the e roads
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        // Undirected graph
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // BFS from node 0
    vector<int> dist(n + 1, -1);
    dist[0] = 0;
    queue<int> q;
    q.push(0);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (auto &v : adj[u])
        {
            if (dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    // Count how many vertices in 1..n have distance = k
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
