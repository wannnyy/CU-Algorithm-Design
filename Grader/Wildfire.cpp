#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long totalBeauty = 0LL;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> b(n), indeg(n, 0);
    vector<vector<int>> adj(n);
    vector<int> burned_field(k);
    vector<bool> burned(n, false);
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        totalBeauty += b[i];
    }

    for (int i = 0; i < k; i++)
    {
        cin >> burned_field[i];
    }

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        indeg[b]++;
    }

    for (int i = 0; i < k; i++)
    {
        int startGrass = burned_field[i];

        if (!burned[startGrass])
        {
            burned[startGrass] = true;
            totalBeauty -= b[startGrass];

            queue<int> Q;
            Q.push(startGrass);
            while (!Q.empty())
            {
                int u = Q.front();
                Q.pop();

                for (int v : adj[u])
                {
                    if (!burned[v])
                    {
                        burned[v] = true;
                        totalBeauty -= b[v];
                        Q.push(v);
                    }
                }
            }
        }
        cout << totalBeauty << " ";
    }

    return 0;
}