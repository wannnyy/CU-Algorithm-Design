#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> n(800, vector<int>(800, -1)), s(800, vector<int>(800, -1));

vector<pair<int, int>> direction = {{0, 1}, {0, -1}, {1, 1}, {1, -1}, {1, 0}, {-1, 1}, {-1, 0}, {-1, -1}};

int main()
{
    int r, c, k;
    cin >> r >> c >> k;

    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            cin >> n[i][j];
        }
    }

    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            cin >> s[i][j];
        }
    }

    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        n[a][b] = 2;
    }
}