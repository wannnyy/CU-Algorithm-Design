#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> start(n), stop(n);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minPQ;
    for (int i = 0; i < n; i++)
        cin >> start[i];
    for (int i = 0; i < n; i++)
        cin >> stop[i];

    for (int i = 0; i < n; i++)
        minPQ.push({stop[i], start[i]});
    int cnt = 0;
    int last_finish = -1;

    while (!minPQ.empty())
    {
        auto [stop, start] = minPQ.top();
        minPQ.pop();
        if (last_finish <= start)
        {
            last_finish = stop;
            cnt += 1;
        }
    }

    cout << cnt;

    return 0;
}