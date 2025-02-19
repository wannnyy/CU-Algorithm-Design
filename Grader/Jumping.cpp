#include <bits/stdc++.h>
#define ll long long

using namespace std;
int n;

int main()
{
    cin >> n;
    vector<ll> v(n), score(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    score[0] = v[0];
    score[1] = v[0] + v[1];
    score[2] = max(score[1] + v[2], v[0] + v[2]);

    for (int i = 3; i < n; i++)
    {
        score[i] += max(max(score[i - 1], score[i - 2]), score[i - 3]) + v[i];
    }

    cout << score[n - 1];
    return 0;
}