#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, k, m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k >> m;
    vector<int> d(n + 1), dp(n + 1);
    for (int i = 1; i < n + 1; i++)
    {
        cin >> d[i];
        d[i] += d[i - 1] - m;
    }

    // for (int i = 0; i < n + 1; i++)
    // {
    //     cout << d[i] << " ";
    // }
    // cout << '\n';

    int p, w;
    while (k--)
    {

        cin >> p >> w;
        int tmp = d[p - 1] + w;
        auto it = lower_bound(d.begin(), d.end(), tmp);
        // while (*it == *(it - 1))
        // {
        //     it--;
        // }
        // cout << *it << '\n';

        cout << it - d.begin() << '\n';
    }

    return 0;
}