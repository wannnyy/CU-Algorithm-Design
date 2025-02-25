#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n, m;
int dp[2][10005];

int main()
{
    cin >> n >> m;
    vector<int> v(n + 1);

    // Read tile sizes
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    // DP initialization
    int now = 1, prev = 0;
    for (int j = 0; j <= m; j++)
    {
        dp[prev][j] = INF;
    }
    dp[prev][0] = 0; // Base case: 0 cost to get area 0

    // Process each tile
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            dp[now][j] = INF; // Reset current row
        }

        for (int j = 0; j <= m; j++)
        {
            if (dp[prev][j] == INF)
                continue; // Skip impossible states

            // Try all valid transformations from v[i]² to k² (1 ≤ k ≤ 100)
            for (int k = 1; k <= 100; k++)
            {
                int new_area = j + k * k;
                if (new_area > m)
                    break; // Stop early if exceeding M

                int cost = (v[i] - k) * (v[i] - k);
                dp[now][new_area] = min(dp[now][new_area], dp[prev][j] + cost);
            }
        }

        swap(now, prev);
    }

    // Output answer
    cout << (dp[prev][m] < INF ? dp[prev][m] : -1);
    return 0;
}
