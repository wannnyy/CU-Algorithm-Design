#include <bits/stdc++.h>

using namespace std;
double bestvalue = -1;
vector<double> w, v, ratio, tail;
// vector<bool> sol;
double W;
int n;

void dfs(int step, double currW, double currV)
{
    if (step == v.size())
    {
        if (currW <= W)
            bestvalue = max(bestvalue, currV);
        return;
    }
    if (currW > W)
        return;
    if (tail[step] + currV < bestvalue)
        return;
    if (step < n)
    {
        // sol[step] = 1;
        dfs(step + 1, currW + w[step], currV + v[step]);
        dfs(step + 1, currW, currV);
    }
    // else
    // {
    //     if(currV > bestvalue && currW <= W )
    //     {
    //         max
    //     }
    // }
}

int main()
{
    cin >> W >> n;
    v.resize(n);
    tail.resize(n);
    w.resize(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = 0; i < n; i++)
        cin >> w[i];
    tail[n - 1] = v[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        tail[i] = tail[i + 1] + v[i];
    }
    dfs(0, 0, 0);

    cout << bestvalue;
    return 0;
}