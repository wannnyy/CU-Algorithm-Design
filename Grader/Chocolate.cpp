#include <bits/stdc++.h>
#define ll long long

using namespace std;
int mod = 1000003;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<ll> v(k + 1), dp(n + 1);

    for (int i = 1; i < 1 + k; i++)
    {
        cin >> v[i];
    }
    dp[0] = 1;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < k + 1; j++)
        {
            if (i - v[j] >= 0)
            {
                dp[i] += dp[i - v[j]];
                dp[i] = dp[i] % mod;
            }
        }
    }

    // for (int i = 1; i < n + 1; i++)
    // {
    //     cout << dp[i] << " ";
    // }
    // cout << '\n';

    cout << dp[n];

    return 0;
}