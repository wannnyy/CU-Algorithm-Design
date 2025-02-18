#include <bits/stdc++.h>
#define ll long long

using namespace std;
int n, md = 100000007;

int main()
{
    cin >> n;
    vector<ll> f(n), f_1(n);
    f[0] = 2;
    f[1] = 4;
    f[2] = 7;

    f_1[0] = 1;
    f_1[1] = 2;
    f_1[2] = 3;

    for (int i = 3; i < n; i++)
    {
        // f[i] = f[i-1] + f[i-3]
        f[i] = f[i - 1] % md + f[i - 3] % md + f_1[i - 1] % md;
        f_1[i] = f[i - 3] % md + f_1[i - 1] % md;
    }

    cout << f[n - 1] % md;
}
