#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ll f, w, n;
    cin >> f >> w >> n;

    vector<int> v(n + 1, -1);

    for (int i = 0; i < f; i++)
    {
        int tmp;
        cin >> tmp;
        v[tmp] = 1;
    }

    bool start = false;
    int idx_start = -1, range = 2 * w + 1, cnt = 0;
    if (w == 0)
        range = 0;
    // total light range is 2 * w + 1;
    for (int i = 1; i < n + 1; i++)
    {
        if (v[i] == 1 && !start) // start must be false. after the first one start is always true?
        {
            idx_start = i;
            start = true;
            cnt++;
            continue;
        }
        else if (v[i] == 1 && start)
        {
            if (abs(i - idx_start) > range)
            {
                idx_start = i;
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}