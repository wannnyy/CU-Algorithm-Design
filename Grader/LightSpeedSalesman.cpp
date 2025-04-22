#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> order(M);
    for (int &x : order)
        cin >> x;

    vector<ll> t(M);
    for (ll &x : t)
        cin >> x;

    // Compute prefix sum of time
    vector<ll> prefix(M + 1, 0);
    for (int i = 0; i < M; i++)
    {
        prefix[i + 1] = prefix[i] + t[i];
    }

    // Total length of the circular road
    ll total_circle = prefix[M];

    // Function to compute clockwise distance from u to v
    auto dist = [&](int u, int v)
    {
        if (u <= v)
            return prefix[v] - prefix[u];
        return total_circle - (prefix[u] - prefix[v]);
    };

    // Compute base time (no portal)
    ll base = 0;
    for (int i = 0; i < M; i++)
    {
        int u = order[i], v = order[(i + 1) % M];
        base += min(dist(u, v), dist(v, u));
    }

    while (N--)
    {
        int A, B;
        cin >> A >> B;

        ll best = base;
        for (int i = 0; i < M; i++)
        {
            int u = order[i], v = order[(i + 1) % M];

            ll normal = min(dist(u, v), dist(v, u));

            // Try going through portal
            ll via1 = dist(u, A) + dist(B, v);
            ll via2 = dist(u, B) + dist(A, v);
            ll via = min(via1, via2);

            best = min(best, base - normal + min(normal, via));
        }

        cout << best << '\n';
    }

    return 0;
}
