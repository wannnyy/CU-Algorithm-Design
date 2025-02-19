#include <bits/stdc++.h>

using namespace std;
int n, a, b, c;

int main()
{
    cin >> n >> a >> b >> c;

    vector<int> v(n + 1), C(3);
    // We define v[i] as the maximum cuts that could be done on string length i.

    C[0] = a;
    C[1] = b;
    C[2] = c;

    sort(C.begin(), C.end());

    v[0] = 0;
    v[a] = 1;
    v[b] = 1;
    v[c] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i - C[j] >= 0 && v[i - C[j]] > 0)
                v[i] = max(v[i], v[i - C[j]] + 1);
        }
    }

    cout << v[n];

    return 0;
}