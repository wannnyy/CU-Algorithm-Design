#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, e, k;
    cin >> n >> e >> k;
    vector<vector<int>> adj(n);

    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int answer = 1;

    for (int i = 0; i < n; i++)
    {
        vector<int> dist(n, -1);

        queue<int> q;
        dist[i] = 0;
        q.push(i);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            if (dist[u] < k)
            {
                for (auto x : adj[u])
                {
                    if (dist[x] == -1)
                    {
                        q.push(x);
                        dist[x] = dist[u] + 1;
                    }
                }
            }
        }
        int reachable = 0;
        for (int j = 0; j < n; j++)
        {
            if (dist[j] != -1 && dist[j] <= k)
            {
                reachable++;
            }
        }
        answer = max(answer, reachable);
    }
    cout << answer;

    return 0;
}