#include <bits/stdc++.h>
#define ll long long

using namespace std;
int n;

int main()
{
    cin >> n;
    vector<int> a(n + 1);

    for (int i = 1; i < n + 1; i++)
    {
        cin >> a[i];
    }

    vector<vector<int>> dp(n + 5, vector<int>(n + 5, 0));

    // how tf does this work?
    for (int sz = 2; sz <= n; sz++)
    {
        for (int l = 1, r = sz; r <= n; l++, r++)
        {
            dp[l][r] = max({dp[l + 2][r] + max(a[l], a[l + 1]),
                            dp[l + 1][r - 1] + max(a[l], a[r]),
                            dp[l][r - 2] + max(a[r], a[r - 1])});
        }
    }

    // for (int i = 1; i < n + 5; i++)
    // {
    //     for (int j = 1; j < n + 5; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << '\n';
    // }

    cout << dp[1][n] << "\n";
    return 0;
}