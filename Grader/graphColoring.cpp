#include <bits/stdc++.h>

using namespace std;
int n, e;
vector<vector<int>> adj;

int main()
{
    cin >> n >> e;
    adj.resize(n);
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    return 0;
}