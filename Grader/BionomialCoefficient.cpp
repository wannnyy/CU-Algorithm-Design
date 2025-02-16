#include <iostream>
#include <vector>
using namespace std;

int binomialCoefficientDP(int n, int k, vector<vector<int>> &dp)
{
    if (k == 0 || k == n)
        return 1;
    if (dp[n][k] != -1)
        return dp[n][k];

    dp[n][k] = binomialCoefficientDP(n - 1, k - 1, dp) + binomialCoefficientDP(n - 1, k, dp);
    return dp[n][k];
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
    cout << binomialCoefficientDP(n, k, dp) << endl;

    return 0;
}
