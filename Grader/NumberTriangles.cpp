#include <bits/stdc++.h>

using namespace std;
int n;

int main()
{
    cin >> n;

    vector<vector<int>> v(n, vector<int>(n * 2, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cin >> v[i][2 * j + n - i];
        }
    }
    // cout << '\n';

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 2; j < 2 * n - 1; j++)
        {
            v[i][j] += max(v[i + 1][j - 1], v[i + 1][j + 1]);
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < 2 * n; j++)
    //     {
    //         cout << v[i][j] << " ";
    //     }
    //     cout << '\n';
    // }

    cout << v[0][n];

    return 0;
}