#include <bits/stdc++.h>
#define ll long long;

using namespace std;
int mod = 1997;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<vector<int>> s(n + 1, vector<int>(k + 1, 0));
    // n is number of our stones, k is the total groups.

    for (int i = 0; i < n + 1; i++)
    {
        s[i][0] = 0;
        s[i][1] = 1;

        if (i == 0)
        {
            s[i][0] = 1;
        }
        if (i == 1)
        {
            s[i][1] = 1;
        }
    }

    for (int i = 2; i < n + 1; i++)
    {
        for (int j = 2; j < min(k, i) + 1; j++)
        {
            s[i][j] = (s[i - 1][j - 1] + j * s[i - 1][j]) % mod;
        }
    }

    cout << s[n][k];

    return 0;
}