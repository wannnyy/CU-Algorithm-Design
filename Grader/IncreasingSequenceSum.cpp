#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    // dp[j] = number of ways to partition j
    vector<long long> dp(N + 1, 0);
    dp[0] = 1; // there’s exactly one way to partition 0: the empty sum

    // For each possible part size i = 1..N,
    // we add it into all sums j from i..N.
    for (int i = 1; i <= N; ++i)
    {
        for (int j = i; j <= N; ++j)
        {
            dp[j] += dp[j - i];
        }
    }

    cout << dp[N] << "\n";
    return 0;
}
