#include <bits/stdc++.h>

using namespace std;
int n, m, k, connect[510][510];
int minDist = 1e9;
vector<int> s, current, mark;

void permute(int state)
{
    if (state == k)
    {
        int curr = 0;
        for (int i = 1; i < k; i++)
        {
            curr += connect[current[i - 1]][current[i]];
        }

        minDist = min(curr, minDist);
    }

    for (int i = 0; i < k; i++)
    {
        if (mark[i])
            continue;

        mark[i] = true;
        current.push_back(s[i]);
        permute(state + 1);
        mark[i] = false;
        current.pop_back();
    }
}

int main()
{
    cin >> n >> m >> k;
    s.resize(k);
    mark.resize(n);
    for (int i = 0; i < k; i++)
    {
        cin >> s[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            connect[i][j] = connect[j][i] = 1e9;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        connect[a][b] = c;
        connect[b][a] = c;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                connect[i][j] = min(connect[i][j], connect[i][k] + connect[k][j]);
            }
        }
    }

    permute(0);

    cout << minDist;

    return 0;
}