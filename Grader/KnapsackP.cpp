#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n + 1), w(n + 1);
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i < n + 1; i++)
    {
        cin >> v[i];
    }

    for (int j = 1; j < n + 1; j++)
    {
        cin >> w[j];
    }

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            cin >> dp[i][j];
        }
    }

    int a = n, b = m;
    vector<int> selected;

    while (a > 0 && b > 0)
    {
        if (dp[a][b] != dp[a - 1][b])
        {
            selected.push_back(a);
            b -= w[a];
        }
        a -= 1;
    }

    cout << selected.size() << '\n';
    for (auto &x : selected)
    {
        cout << x << " ";
    }

    return 0;
}