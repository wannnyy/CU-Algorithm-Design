#include <iostream>
#include <cstring> // For memset
using namespace std;

int N, M, K;
int dp[31][2][31][31]; // Memoization table

// Recursive function with memoization
int count_barcodes(int pos, int last_color, int streak, int changes)
{
    if (pos == N)
        return (changes == K) ? 1 : 0;
    if (dp[pos][last_color][streak][changes] != -1)
        return dp[pos][last_color][streak][changes];

    int total_ways = 0;

    // Try adding a black (0)
    if (last_color == 0)
    {
        if (streak < M)
        {
            total_ways += count_barcodes(pos + 1, 0, streak + 1, changes);
        }
    }
    else
    {
        total_ways += count_barcodes(pos + 1, 0, 1, changes + 1);
    }

    // Try adding a white (1)
    if (last_color == 1)
    {
        if (streak < M)
        {
            total_ways += count_barcodes(pos + 1, 1, streak + 1, changes);
        }
    }
    else
    {
        total_ways += count_barcodes(pos + 1, 1, 1, changes + 1);
    }

    return dp[pos][last_color][streak][changes] = total_ways;
}

int main()
{
    cin >> N >> M >> K;
    memset(dp, -1, sizeof(dp));                 // Initialize memoization table with -1
    cout << count_barcodes(1, 0, 1, 0) << endl; // Start with first black line
    return 0;
}
