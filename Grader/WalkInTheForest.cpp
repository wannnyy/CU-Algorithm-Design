#include <bits/stdc++.h>

using namespace std;
int n, m;
int main()
{
    cin >> n >> m;
    vector<vector<int>> v(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            cin >> v[i][j];
        }
    }
    // cout << '\n';

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (i == 1)
            {
                v[i][j] += v[i][j - 1];
            }
            else if (j == 1)
            {
                v[i][j] += v[i - 1][j];
            }
            else
            {
                v[i][j] = max(max(v[i - 1][j - 1] + 2 * v[i][j], v[i - 1][j] + v[i][j]), v[i][j - 1] + v[i][j]);
            }
        }
    }
    // for (int i = 0; i < n + 1; i++)
    // {
    //     for (int j = 0; j < m + 1; j++)
    //     {
    //         cout << v[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    cout << v[n][m];

    return 0;
}
