#include <bits/stdc++.h>

using namespace std;
#define ll long long
int n, m;
vector<ll> chef;

ll solve(ll time)
{
    ll tmp = 0;
    for (int i = 0; i < n; i++)
    {
        tmp += time / chef[i];
    }
    return tmp;
}

int main()
{
    cin >> n >> m;
    chef.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> chef[i];
    }

    sort(chef.begin(), chef.end());
    ll customer;
    for (int i = 0; i < m; i++)
    {
        cin >> customer;
        customer -= n;
        if (customer <= 0)
        {
            cout << "0" << '\n';
            continue;
        }

        ll left = 1, right = chef[0] * customer;
        ll mid = (left + right) / 2;
        while (left < right)
        {
            ll tmp = solve(mid); // total served customers
            if (tmp < customer)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
            mid = (left + right) / 2;
        }
        cout << right << '\n';
    }

    return 0;
}