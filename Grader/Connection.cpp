#include <bits/stdc++.h>
using namespace std;

static const int MAXN = 1000;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, E, K;
    cin >> N >> E >> K;

    vector<vector<int>> adj(N);

    // Read E edges
    for (int i = 0; i < E; i++)
    {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
        adj[B].push_back(A);
    }

    int answer = 1; // At least the student itself is always counted

    // For each student, do a BFS up to distance K
    for (int start = 0; start < N; start++)
    {
        vector<int> dist(N, -1);
        dist[start] = 0;

        queue<int> q;
        q.push(start);

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            // If we haven't reached K steps, we can explore further
            if (dist[u] < K)
            {
                for (int v : adj[u])
                {
                    if (dist[v] == -1)
                    {
                        dist[v] = dist[u] + 1;
                        q.push(v);
                    }
                }
            }
        }

        // Count how many are reachable within distance K
        int reachable = 0;
        for (int i = 0; i < N; i++)
        {
            if (dist[i] != -1 && dist[i] <= K)
            {
                reachable++;
            }
        }

        answer = max(answer, reachable);
    }

    cout << answer << "\n";
    return 0;
}
