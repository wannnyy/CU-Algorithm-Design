#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    double w;
    ll n;
    cin >> w >> n;
    vector<double> tv(n), tw(n);
    double sum = 0.0;
    priority_queue<pair<double, double>, vector<pair<double, double>>> maxPQ;
    for (int i = 0; i < n; i++)
    {
        cin >> tv[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> tw[i];
    }

    for (int i = 0; i < n; i++)
    {
        maxPQ.push({tv[i] / tw[i], i});
    }

    while (w > 0 && !maxPQ.empty())
    {
        auto [_, idx] = maxPQ.top();
        maxPQ.pop();

        if (w >= tw[idx])
        {
            w -= tw[idx];
            sum += tv[idx];
        }
        else if (w < tw[idx])
        {
            sum += (w / tw[idx]) * tv[idx];
            w -= tw[idx];
        }
    }

    std::cout << std::fixed
              << std::setprecision(4)
              << sum
              << '\n';

    return 0;
}