#include <bits/stdc++.h>

using namespace std;

int main()
{
    int r, c;
    cin >> r >> c;
    int mx = 1;

    vector<vector<int>> v(r, vector<int>(c, 0)), dp(r, vector<int>(c, 0));
    string s;

    for (int i = 0; i < r; i++)
    {
        cin >> s;
        for (int j = 0; j < c; j++)
        {
            // cin >> v[i][j];
            v[i][j] = int(s[j] - 48);
            dp[i][j] = v[i][j];
        }
    }

    for (int i = 1; i < r; i++)
    {
        for (int j = 1; j < c; j++)
        {
            // if (dp[i - 1][j - 1] == dp[i - 1][j] && dp[i][j - 1] >= dp[i - 1][j])
            // {
            //     dp[i][j] = dp[i - 1][j - 1] + 1;
            // }
            // else
            // {
            //     dp[i][j] = max(max(dp[i][j - 1], dp[i - 1][j - 1]), dp[i - 1][j]);
            // }
            if (dp[i][j - 1] != 0 && dp[i - 1][j - 1] != 0 && dp[i - 1][j] != 0 && dp[i][j] != 0)
            {

                dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j - 1]), dp[i - 1][j]) + 1;
                mx = max(mx, dp[i][j]);
            }
        }
    }

    // for (int i = 0; i < r; i++)
    // {
    //     for (int j = 0; j < c; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << '\n';
    // }

    cout << mx;

    return 0;
}