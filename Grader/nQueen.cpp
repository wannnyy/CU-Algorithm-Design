#include <bits/stdc++.h>

using namespace std;
int ans = 0, q[20], used[20], n;
bool check(int depth)
{
    for (int i = 0; i < depth; i++)
    {
        if (abs(i - depth) == abs(q[i] - q[depth]))
            return false;
    }
    return true;
}

void dfs(int depth)
{
    if (depth >= n)
    {
        ans++;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (used[i])
            continue;
        q[depth] = i;
        used[i] = true;
        if (check(depth))
        {
            dfs(depth + 1);
        }
        used[i] = false;
    }
}

int main()
{
    cin >> n;
    dfs(0);
    cout << ans;
    return 0;
}