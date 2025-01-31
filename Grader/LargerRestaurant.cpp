#include <bits/stdc++.h>

using namespace std;
int n, a;
vector<long long> t, c;

// queue<long long> c;
priority_queue<pair<long, long>> seat;
map<long long, long long> mp;

int main()
{
    cin >> n >> a;
    t.resize(n);
    c.resize(a);
    for (int i = 0; i < n; i++)
    {
        cin >> t[i];
        seat.push({t[i], i});
    }
    for (int i = 0; i < a; i++)
    {
        cin >> c[i];
    }

    return 0;
}