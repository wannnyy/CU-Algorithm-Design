#include <bits/stdc++.h>

using namespace std;
int n;

int glob_min(vector<int> &v)
{
    int cnt = 0, mn = 1e9;
    for (int i = 0; i < n; i++)
    {
        cnt = min(cnt + v[i], v[i]);
        mn = min(mn, cnt);
    }
    return mn;
}

int kadane(vector<int> &v)
{
    int cnt = 0, mx = -1e9;
    for (int i = 0; i < n; i++)
    {
        cnt = max(v[i], cnt + v[i]);
        mx = max(cnt, mx);
    }
    return mx;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    vector<int> v(n);
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        total += v[i];
    }

    // We can find the global minimum then subtrack it
    int glb_min = glob_min(v);
    int glb_max = kadane(v);

    if (glb_max < 0)
    {
        cout << glb_max;
    }
    else
    {
        cout << max(glb_max, total - glb_min);
    }

    return 0;
}