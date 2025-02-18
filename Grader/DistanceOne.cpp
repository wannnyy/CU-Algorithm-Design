#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, k;
int md = 100000007;

int main()
{
    cin >> n >> k;
    vector<ll> f(n, 0);
    if (k == 1)
    {
        cout << 0;
        return 0;
    }

    f[0] = 2; // Define as total possible solutions
    for (int i = 0; i < k; i++)
    {
        f[i] = i + 2; // Why
    }
    for (int i = k; i < n; i++)
    {
        f[i] = (f[i - 1] + f[i - k]) % md;
    }
    cout << f[n - 1] % md;
}