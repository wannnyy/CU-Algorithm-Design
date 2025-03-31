#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int R, C;
    cin >> R >> C;

    vector<string> maze(R);
    for (int i = 0; i < R; i++)
    {
        cin >> maze[i];
    }

    // If the start or end cells are obstacles, immediately return -1
    if (maze[0][0] == '#' || maze[R - 1][C - 1] == '#')
    {
        cout << -1 << "\n";
        return 0;
    }

    // dist array to keep track of the distance to each cell
    // Initialize with -1 to indicate unvisited
    vector<vector<int>> dist(R, vector<int>(C, -1));

    // Directions: up, down, left, right
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    // BFS queue
    queue<pair<int, int>> q;

    // Start BFS from (0,0)
    dist[0][0] = 1;
    q.push({0, 0});

    while (!q.empty())
    {
        auto [r, c] = q.front();
        q.pop();

        // If we've reached the bottom-right cell, we can stop
        if (r == R - 1 && c == C - 1)
        {
            cout << dist[r][c] << "\n";
            return 0;
        }

        // Check all 4 neighbors
        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            // Check boundaries
            if (nr < 0 || nr >= R || nc < 0 || nc >= C)
                continue;

            // Check if it's an empty cell and not visited yet
            if (maze[nr][nc] == '.' && dist[nr][nc] == -1)
            {
                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }

    // If we exit the loop without reaching (R-1, C-1), there's no path
    cout << -1 << "\n";
    return 0;
}
