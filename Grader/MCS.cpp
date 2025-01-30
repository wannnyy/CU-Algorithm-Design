#include <bits/stdc++.h>

using namespace std;
int n;

int main()
{
    cin >> n;
    vector<int> v(n);
    int mx = -1e9;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        cnt = max(v[i], cnt + v[i]);
        mx = max(cnt, mx);
        // cout << cnt << '\n';
    }

    cout << mx;
    return 0;
}