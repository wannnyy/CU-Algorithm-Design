#include <bits/stdc++.h>

#define ll long long

using namespace std;
int n, m, k;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;

    vector<vector<ll>> v(n, vector<ll>(m, 0)), dp(n, vector<ll>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }

    dp[0][0] = v[0][0];
    for (int i = 1; i < m; i++)
    {
        dp[0][i] = dp[0][i - 1] + v[0][i];
    }

    for (int i = 1; i < n; i++)
    {
        dp[i][0] = dp[i - 1][0] + v[i][0];
        for (int j = 1; j < m; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + v[i][j];
        }
    }

    int r1, c1, r2, c2;

    while (k--)
    {
        cin >> r1 >> c1 >> r2 >> c2;
        // cout << dp[r2][c2] - dp[r1 - 1][c2] - dp[r2][c1 - 1] + dp[r1 - 1][c1 - 1] << '\n';
        ll p1 = dp[r2][c2], p2 = 0, p3 = 0, p4 = 0;

        if (r1 - 1 >= 0)
        {
            p2 = dp[r1 - 1][c2];
        }
        if (c1 - 1 >= 0)
        {
            p3 = dp[r2][c1 - 1];
        }

        if (c1 - 1 >= 0 && r1 - 1 >= 0)
        {
            p4 = dp[r1 - 1][c1 - 1];
        }

        cout << p1 - p2 - p3 + p4 << '\n';
    }

    return 0;
}