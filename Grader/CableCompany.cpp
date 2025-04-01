#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<vector<int>> cost(N, vector<int>(N, 0));

    for (int i = 0; i < N - 1; i++)
    {
        for (int k = 0; k < N - i - 1; k++)
        {
            int c;
            cin >> c;
            int j = i + k + 1;
            cost[i][j] = c;
            cost[j][i] = c;
        }
    }

    vector<bool> visited(N, false);
    vector<int> dist(N, INT_MAX);

    dist[0] = 0;
    long long totalCost = 0;
    for (int i = 0; i < N; i++)
    {
        // 1. Pick the unvisited node with the smallest dist
        int u = -1;
        int minDist = INT_MAX;
        for (int v = 0; v < N; v++)
        {
            if (!visited[v] && dist[v] < minDist)
            {
                minDist = dist[v];
                u = v;
            }
        }

        // 2. Mark u as visited, add its connection cost to totalCost
        visited[u] = true;
        totalCost += minDist;

        // 3. Update dist[] for the unvisited neighbors of u
        for (int v = 0; v < N; v++)
        {
            if (!visited[v] && cost[u][v] < dist[v])
            {
                dist[v] = cost[u][v];
            }
        }
    }

    // Output the minimal total cost
    cout << totalCost << "\n";
    return 0;

    return 0;
}