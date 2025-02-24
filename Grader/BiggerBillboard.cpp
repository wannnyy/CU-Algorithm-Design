#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n + 1), customer(n + 1);

    for (int i = 1; i < n + 1; i++)
    {
        cin >> v[i];
    }
    customer[1] = v[1];
    customer[2] = v[2];
    customer[3] = v[3];

    for (int i = 4; i < n + 1; i++)
    {
        customer[i] = max(max(customer[i - 3] + v[i], customer[i - 1]), customer[i - 2]);
    }

    cout << customer[n];
}
