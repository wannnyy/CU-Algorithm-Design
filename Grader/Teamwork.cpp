#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main()
{

    ll n, m;
    cin >> n >> m;
    priority_queue<ll, vector<ll>, greater<ll>> minPQ;
    vector<ll> v(m);
    ll sum = 0;
    double cnt = 0.0;
    for (int i = 0; i < m; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    // we gonna work by finished time.
    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        minPQ.push(v[i]);
    }
    idx += n;

    while (!minPQ.empty())
    {
        int tmp = minPQ.top();
        minPQ.pop();
        sum += tmp;
        if (idx < m)
        {
            minPQ.push(v[idx] + tmp);
            idx += 1;
        }
        cnt += 1;
        // cout << idx;
    }
    std::cout << std::fixed
              << std::setprecision(3)
              << sum / cnt
              << '\n'; // outputs: 3.142
    // cout << sum / cnt;
    return 0;
}