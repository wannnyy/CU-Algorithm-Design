#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> height;
ll n, d;
ll cal(ll K)
{
    int days = 0;
    int idx = -1;
    while (idx < n - 1)
    {
        days++;
        ll current_height = (idx == -1 ? 0 : height[idx]);
        auto next = int(upper_bound(height.begin(), height.end(), current_height + K) - height.begin()) - 1;
        // idx = next;
        if (next == idx)
        {
            return d + 1;
        }
        idx = next;
        if (days > d)
            return days;
    }
    return days;
}

int main()
{
    cin >> n >> d;
    height.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> height[i];
    }

    ll lo = 1, hi = height[n - 1], ansK = hi;
    while (lo <= hi)
    {
        ll mid = lo + (hi - lo) / 2;
        if (cal(mid) <= d) // We still have some days left so we lower the K down.
        {
            ansK = mid;
            hi = mid - 1;
        }
        else // We take too long so we bumps the K up.
        {
            lo = mid + 1;
        }
    }

    int used_days = cal(ansK);
    cout << ansK << " " << used_days;

    return 0;
}