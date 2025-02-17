#include <bits/stdc++.h>
#define ll long long

using namespace std;
int n, k;
vector<int> c, a;

ll pm(ll a, ll b, int k)
{
    return ((a % k) * (b % k)) % k;
}

ll ps(ll a, ll b, int k)
{
    return ((a % k) + (b % k)) % k;
}

// ll solve(vector<ll> &v)
// {
// }

int main()
{
    cin >> k >> n;
    // vector<vector<ll>> v(n, vector<ll>(k, 0));
    vector<ll> v(n + 1);
    c.resize(k);
    a.resize(k);
    int md = 32717;

    for (int i = 0; i < k; i++)
    {
        cin >> c[i];
    }

    for (int i = 0; i < k; i++)
    {
        cin >> a[i];
        v[i] = a[i];
    }

    for (int i = k; i <= n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            v[i] = ps(v[i], pm(c[k - j - 1], v[j + i - k], md), md);
            // v[i] += pm(c[k - j - 1], v[j + i - k], md);
            // v[i] += c[k - j - 1] * v[j + i - k];
        }
        // v[i] = v[i] % md;
        // cout << v[i] << '\n';
    }

    cout << v[n];

    return 0;
}

/*
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MOD = 32717;

int main() {
    int k, n;
    cin >> k >> n;

    vector<int> c(k), a(k);

    for (int i = 0; i < k; i++) cin >> c[i];  // Read coefficients c_1, c_2, ..., c_k
    for (int i = 0; i < k; i++) cin >> a[i];  // Read base values a_0, a_1, ..., a_(k-1)

    // Base case: if n < k, return a_n
    if (n < k) {
        cout << a[n] % MOD << '\n';
        return 0;
    }

    // Vector to store results up to R(n)
    vector<ll> dp(n + 1, 0);

    // Initialize first k values
    for (int i = 0; i < k; i++)
        dp[i] = a[i];

    // Compute R(n) iteratively
    for (int i = k; i <= n; i++) {
        dp[i] = 0;
        for (int j = 0; j < k; j++) {
            dp[i] = (dp[i] + (1LL * c[j] * dp[i - j - 1]) % MOD) % MOD;
        }
    }

    // Output the final result
    cout << dp[n] << '\n';

    return 0;
}
*/