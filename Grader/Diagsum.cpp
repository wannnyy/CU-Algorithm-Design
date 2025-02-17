#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n, 0)), dp(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
            if (i == 0 || j == 0)
            {
                dp[i][j] = v[i][j];
            }
        }
    }
    int ans = -1e8;
    // Compute along the row first
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            for (int p = 0; p < n; p++)
            {
                if (i + p < n && j + p < n)
                {
                    dp[i][j] = max(v[i][j], dp[i - 1][j - 1] + v[i][j]);
                    ans = max(ans, dp[i][j]);
                }
                else
                {
                    continue;
                }
            }
        }
    }

    cout << ans;

    return 0;
}