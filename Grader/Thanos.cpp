#include <bits/stdc++.h>

#define ll long long

using namespace std;
ll p, k, A, B, n;
vector<int> v;

ll solve(ll l, ll r)
{
    ll avenger = upper_bound(v.begin(), v.end(), r) - v.begin() - (lower_bound(v.begin(), v.end(), l) - v.begin());

    if (avenger == 0)
    {
        return A;
    }

    ll current = (avenger) * (r - l + 1) * B;
    if (r - l == 0)
        return current;

    ll mid = (l + r) / 2;

    return min(current, solve(l, mid) + solve(mid + 1, r));
}

int main()
{
    cin >> n >> k >> A >> B;
    ll p = (1 << n);
    v.resize(k);
    for (int i = 0; i < k; i++)
    {
        cin >> v[i];
        v[i] = v[i] - 1;
    }

    sort(v.begin(), v.end());

    cout << solve(0, p - 1);

    return 0;
}