#include <bits/stdc++.h>
#define ll long long
int mod = 100000007;

using namespace std;
int n;

int main()
{
    cin >> n;
    vector<ll> f(n + 1);

    // For each digit we have 3 possible choices 1, 2, 3.

    f[1] = 3;
    f[2] = 7;
    f[3] = 15;
    for (int i = 4; i <= n; i++)
    {
        f[i] = (2 * f[i - 1] + f[i - 3]) % mod;
    }

    cout << f[n] % mod;
}