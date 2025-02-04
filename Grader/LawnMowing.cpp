#include <bits/stdc++.h>

#define ll long long
using namespace std;
ll n, m, k;
ll a, b;
ll cost;
vector<ll> A;

ll solve(int l, int r)
{
    // ll cur = 0;
    // for (int i = l; i <= r; i++)
    // {
    //     cur += A[i];
    // }

    // cur += (r - l + 1) * k; // total wages
    // int mid = (l + r) / 2;

    // if (l == r)
    //     return cur -= (r - l + 1) * k;

    // ll cur = A[r] - A[a] + (r - a + 1) * k;
    ll cur = A[r] - cost;
    cur += (r - a + 1) * k;
    if (l == r)
    {
        if (cur <= b)
            return A[r] - cost;
        else
            return 0;
    }
    // return cur;

    int mid = (l + r) / 2;
    // if (cur > b)
    // {
    //     cout << "> " << l << " " << mid << '\n';
    //     return solve(l, mid);
    // }
    // else
    // {
    //     cout << "< " << mid + 1 << " " << r << '\n';
    //     return solve(mid + 1, r);
    // }
    // return max(solve(l, mid), solve(mid + 1, r));
    if (cur <= b)
        return max(solve(l, mid), solve(mid + 1, r));
    else
        return solve(l, mid);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    A.resize(n);
    cin >> A[0];
    for (int i = 1; i < n; i++)
    {
        cin >> A[i];
        A[i] += A[i - 1];
    }

    while (m--)
    {
        cin >> a >> b;
        /*
            A[r] = A[0] + ... + A[r]
            A[a] = A[0] + ... + A[a]

        */
        if (b == 0)
        {
            cout << "0\n";
            continue;
        }

        if (a == 0)
            cost = 0;
        else
            cost = A[a - 1];

        cout << solve(a, n - 1) << '\n';
    }
    return 0;
}