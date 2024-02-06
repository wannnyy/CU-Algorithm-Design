#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<int> arr, Q(q), sz, index;
    vector<pair<int, int>> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i].first >> s[i].second;
        index.push_back(s[i].first);
    }

    for (int i = 0; i < q; i++)
    {
        cin >> Q[i]; // have to minus 1
    }

    sort(s.begin(), s.end());
    sort(index.begin(), index.end());

    sz.push_back(s[0].second);

    for (int i = 1; i < n; i++)
    {
        sz.push_back(s[i].second + sz[i - 1]);
    }

    // for(int i=0;i<n;i++)
    // {
    //     cout << sz[i] <<  " " ;
    // }
    // cout << '\n';
    // for(int i=0;i<n;i++)
    // {
    //     cout << index[i] << " ";
    // }
    // cout << '\n';

    for (int i = 0; i < q; i++)
    {
        int prob = Q[i] ;
        auto it = lower_bound(sz.begin(), sz.end(), prob) - sz.begin();
        // cout << it << " ";
        cout << index[it] << '\n';
    }

    return 0;
}