#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    vector<int> indeg(n), ans;
    for (int i = 0; i < n; i++)
    {
        int m, a;
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            cin >> a;
            adj[a].push_back(i);
            indeg[i]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indeg[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        ans.push_back(u);
        for (auto x : adj[u])
        {
            indeg[x]--;
            if (indeg[x] == 0)
            {
                q.push(x);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}