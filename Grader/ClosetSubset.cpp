#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <tuple>
#include <algorithm>
#include <unordered_set>
#include <set>

using namespace std;
vector<int> a;
int n, m, k;
int ans, best;

typedef tuple<int, int, int, int> node; // cost, idx (index to be done), chosen, sum
                                        //

vector<int> prefix;

int max_sum(int idx, int remain)
{
    if (idx >= n)
        return 0;
    if (idx == 0)
        return prefix[idx + remain - 1];
    return prefix[idx + remain - 1] - prefix[idx - 1];
}

int min_sum(int idx, int remain)
{
    if (idx >= n)
        return 0;
    if (remain == n)
        return prefix[n - 1];
    return prefix[n - 1] - prefix[n - 1 - remain];
}

int heuristic(int idx, int chosen, int sum)
{
    int remain = m - chosen;
    int max_value = sum + max(0, max_sum(idx, remain));
    int min_value = sum + min(0, min_sum(idx, remain));
    if (k < min_value)
        return min_value - k;
    if (k > max_value)
        return k - max_value;
    return 0;
}

void search(int idx, int choose, int sum)
{
    if (idx == n)
    {
        if (abs(sum - k) < best)
        {
            best = abs(sum - k);
            ans = sum;
        }
    }
    else
    {
        if (heuristic(idx, choose, sum) > best)
            return;
        if ((n - m) - (idx - choose) > 0)
        {
            search(idx + 1, choose, sum);
        }
        if (choose < m)
        {
            search(idx + 1, choose + 1, sum + a[idx]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    a.resize(n);
    prefix.resize(n);
    best = INT_MAX;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end(), greater<int>());
    prefix[0] = a[0];
    for (int i = 1; i < n; i++)
        prefix[i] = prefix[i - 1] + a[i];

    search(0, 0, 0);

    cout << best << endl;
}
