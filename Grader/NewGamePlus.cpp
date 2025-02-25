#include <bits/stdc++.h>
#define ll long long
using namespace std;
int R, C;
int dp[505][505][4], v[505][505];
int mod = 100000007;

ll solve(int r, int c, int prev)
{
    ll total = 0;
    if (c >= C || r >= R || r < 0 || c < 0)
    {
        return 0;
    }
    if (v[r][c] == 1)
        return 0;
    if (c == C - 1)
    {
        return 1;
    }

    if (dp[r][c][prev] != -1)
    {
        return dp[r][c][prev];
    }

    if (prev == 0)
    {
        total += solve(r, c + 1, 1) % mod + solve(r + 1, c + 1, 2) % mod;
    }
    else if (prev == 1)
    {
        total += solve(r - 1, c + 1, 0) % mod + solve(r + 1, c + 1, 2) % mod;
    }
    else if (prev == 2)
    {
        total += solve(r - 1, c + 1, 0) % mod + solve(r, c + 1, 1) % mod;
    }
    else if (prev == 3)
    {
        total += solve(r - 1, c + 1, 0) % mod + solve(r, c + 1, 1) % mod + solve(r + 1, c + 1, 2) % mod;
    }

    dp[r][c][prev] = total % mod;
    return total % mod;
}

// 0 x
// 1 y
// 2 z
// 3 any

int main()
{
    cin >> R >> C;

    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> v[i][j];
        }
    }

    ll tmp = 0;

    for (int i = 0; i < R; i++)
    {
        tmp += solve(i, 0, 3) % mod;
    }
    cout << tmp % mod;

    return 0;
}