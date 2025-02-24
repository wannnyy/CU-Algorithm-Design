#include <bits/stdc++.h>

using namespace std;
int n, m;

int main()
{
    cin >> n >> m;
    vector<int> v(n), ans(m + 1, m + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    ans[0] = 0;
    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i - v[j] >= 0)
            {
                ans[i] = min(ans[i], ans[i - v[j]] + 1);
            }
        }
    }

    cout << ans[m];

    return 0;
}