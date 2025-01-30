#include <bits/stdc++.h>

using namespace std;
int n;

int kadane(vector<int> &v, int start)
{
    int cnt = 0;
    int mx = -1e9;
    for (int i = start; i < n; i++)
    {
        cnt = max(v[i], cnt + v[i]);
        mx = max(mx, cnt);
    }
    return mx;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int cnt1 = 0, cnt2 = 0;
    int mx1 = -1e9;
    int ans = -1e9;

    for (int i = 0; i < n; i++)
    {
        cnt1 += v[i];
        if (cnt1 > mx1)
        {
            cnt2 = kadane(v, i + 1);
            mx1 = cnt1;
            cout << mx1 << " " << cnt2 << "\n";
            int tmp = max(mx1, cnt2);
            ans = max(max(ans, mx1 + cnt2), tmp);
        }
        if (cnt1 < 0)
            cnt1 = 0;
    }
    cout << ans;

    // for (int i = 0, s = 0; i < n; i++)
    // {
    //     cnt1 += v[i];
    //     if (cnt1 > mx1)
    //     {
    //         mx1 = cnt1;
    //         start = s;
    //         end = i;
    //     }
    //     if (cnt1 < 0)
    //     {
    //         if (mx1 > 0)
    //         {
    //             break;
    //         }
    //         else
    //         {
    //             cnt1 = 0;
    //             s = i + 1;
    //             end = i;
    //         }
    //     }
    // }

    // for (int i = end + 1; i < n; i++)
    // {
    //     cnt2 += v[i];
    //     if (cnt2 > mx2)
    //     {
    //         mx2 = cnt2;
    //     }
    //     if (cnt2 < 0)
    //     {
    //         cnt2 = 0;
    //     }
    // }
    // // cout << mx1 << " " << mx2 << " " << mx1 + mx2 << '\n';
    // cout << max(max(mx1, mx2), mx2 + mx1);
}