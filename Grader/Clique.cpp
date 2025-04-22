#include <bits/stdc++.h>

using namespace std;
int n, best = -1;
vector<int> B, tail, used;
vector<vector<int>> F;
bool check(int idx)
{
    for (int i = 0; i < n; i++)
    {
        if (!F[i][idx] && used[i])
        {
            return false;
        }
    }
    return true;
}

void solve(int idx, int sum)
{
    if (idx >= n)
    {
        best = max(sum, best);
        return;
    }
    if (tail[idx] + sum <= best)
        return;

    if (check(idx))
    {
        used[idx] = true;
        solve(idx + 1, sum + B[idx]);
        used[idx] = false;
    }
    solve(idx + 1, sum);
}

int main()
{
    cin >> n;
    B.resize(n);
    used.resize(n);
    tail.resize(n);
    F.resize(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        cin >> B[i];
    }
    tail[n - 1] = B[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        tail[i] = tail[i + 1] + B[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> F[i][j];
        }
    }

    solve(0, 0);
    cout << best;
    return 0;
}