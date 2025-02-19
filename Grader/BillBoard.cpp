#include <bits/stdc++.h>

using namespace std;
int n;

int main()
{
    cin >> n;
    vector<int> v(n + 1), customer(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    customer[1] = v[1];
    for (int i = 2; i <= n; i++)
    {
        customer[i] = max(customer[i - 2] + v[i], customer[i - 1]);
    }

    cout << customer[n];

    return 0;
}