#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, m, k;
    cin >> n >> m >> k;

    // start empty, reserve to avoid reallocations
    vector<array<int, 3>> actions;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> request, produced;
    // priority_queue<pair<int, int>, vector<pair<int, int>>> request, produced;
    actions.reserve(k);

    for (int i = 0; i < k; i++)
    {
        int d, e, l;
        cin >> d >> e >> l;
        actions.push_back({d, e, l});
    }

    sort(actions.begin(), actions.end());
    // now actions.size() == k, indexed 0..k-1

    for (auto &act : actions)
    {
        // cout << act[0] << '\n';
        int d, e, l;
        d = act[0];
        e = act[1];
        l = act[2];

        if (e == 0)
        {
            if (!request.empty())
            {
                // time, store
                auto [_, store] = request.top();
                request.pop();
                cout << store << '\n';
            }
            else
            {
                // time produced, store.
                produced.push({d, l});
                cout << 0 << '\n';
            }
        }
        else if (e == 1)
        {
            if (!produced.empty())
            {
                auto [_, plant] = produced.top();
                produced.pop();
                cout << plant << '\n';
            }
            else
            {
                request.push({d, l});
                cout << 0 << '\n';
            }
        }
    }

    return 0;
}
