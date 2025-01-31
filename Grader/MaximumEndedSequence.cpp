#include <bits/stdc++.h>

using namespace std;
int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    vector<int> v(n + 1);
    unordered_map<int, vector<int>> mp;
    int mx = -1e9;
    for (int i = 1; i < n + 1; i++)
    {
        cin >> v[i];
        if (mp.find(v[i]) == mp.end())
        {
            mp[v[i]] = {i};
        }
        else
        {
            mp[v[i]].push_back(i);
        }

        v[i] = v[i] + v[i - 1];
    }

    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout << v[i] << " ";
    // }
    // cout << '\n';

    for (auto x : mp)
    {
        // x will be pair of keys & vectors.
        // cout << x.first << " ";
        auto tmp = x.second;
        int sz = tmp.size();
        // for (int i = 0; i < sz; i++)
        // {
        //     for (int j = i; j < sz; j++)
        //     {
        //         // cout << v[tmp[j]] << " " << v[tmp[i]] << '\n';
        //         if (i == j)
        //             if (tmp[i] == 0)
        //                 mx = max(mx, v[tmp[i]]);
        //             else
        //                 mx = max(mx, v[tmp[i]] - v[tmp[i] - 1]);
        //         else if (tmp[i] - 1 > 0)
        //             mx = max(mx, v[tmp[j]] - v[tmp[i] - 1]);
        //         else
        //             mx = max(mx, v[tmp[j]]);
        //     }
        // }
        int tmp_mx = -1e9, tmp_mn = 1e9;
        int idx_mx = 0, idx_mn = 0;
        for (int i = 0; i < sz; i++)
        {
            if (v[tmp[i]] > tmp_mx)
            {
                tmp_mx = v[tmp[i]];
                idx_mx = tmp[i];
            }
            if (v[tmp[i]] < tmp_mn)
            {
                tmp_mn = v[tmp[i]];
                idx_mn = tmp[i] - 1;
            }
            tmp_mx = max(v[tmp[i]], tmp_mx);
            tmp_mn = min(v[tmp[i]], tmp_mn);
        }
        // cout << tmp_mx << " " << tmp_mn << "\n";
        // mx = max(mx, tmp_mx - tmp_mn);
        mx = max(mx, v[idx_mx] - v[idx_mn]);
    }

    cout << mx;

    return 0;
}