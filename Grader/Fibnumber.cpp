#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int n;
    cin >> n;
    ll n_1 = 0, n_2 = 1, ans = 0;
    if (n == 0 || n == 1)
    {
        cout << n;
        return 0;
    }
    for (int i = 0; i < n - 1; i++)
    {
        ans = n_1 + n_2;
        n_1 = n_2;
        n_2 = ans;
    }
    cout << ans;
    return 0;
}
