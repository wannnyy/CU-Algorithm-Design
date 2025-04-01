#include <bits/stdc++.h>

using namespace std;
static const int DIRECTIONS[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int r, c;
    long long T;
    cin >> r >> c >> T;
    int answer = 0;

    vector<vector<int>> grid(r, vector<int>(c));
    vector<vector<long long>> infected(r, vector<long long>(c, -1));

    queue<pair<int, int>> q;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 1)
            {
                infected[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (auto &dir : DIRECTIONS)
        {
            int nx = x + dir[0];
            int ny = y + dir[1];

            if (nx >= 0 && nx < r && ny >= 0 && ny < c)
            {
                if (infected[nx][ny] == -1 && grid[nx][ny] != 2)
                {
                    infected[nx][ny] = infected[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (infected[i][j] <= T && infected[i][j] != -1)
            {
                answer++;
            }
        }
    }

    cout << answer;
    return 0;
}