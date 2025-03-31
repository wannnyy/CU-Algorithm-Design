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

    vector<vector<int>> grid(r, vector<int>(c));
    // ค่า -1 หมายถึงยังไม่ติดเชื้อ
    vector<vector<long long>> infected_day(r, vector<long long>(c, -1));

    queue<pair<int, int>> q;

    // อ่านตาราง
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> grid[i][j];
        }
    }

    // ใส่ทุกช่องที่เริ่มติดเชื้อ (grid[i][j] == 1) เข้าคิวด้วยวันติดเชื้อ = 0
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (grid[i][j] == 1)
            {
                infected_day[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    // BFS
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        long long current_day = infected_day[x][y];

        for (auto &dir : DIRECTIONS)
        {
            int nx = x + dir[0];
            int ny = y + dir[1];

            // เช็คขอบเขต และ เช็คว่าช่องนี้ไม่ใช่ภูเขา และยังไม่เคยติดเชื้อมาก่อน
            if (nx >= 0 && nx < r && ny >= 0 && ny < c)
            {
                if (grid[nx][ny] != 2 && infected_day[nx][ny] == -1)
                {
                    // ติดเชื้อในวันถัดไป
                    infected_day[nx][ny] = current_day + 1;
                    q.push({nx, ny});
                }
            }
        }
    }

    // นับจำนวนช่องที่ติดเชื้อภายใน T วัน
    long long answer = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (infected_day[i][j] != -1 && infected_day[i][j] <= T)
            {
                answer++;
            }
        }
    }

    cout << answer << "\n";

    return 0;
}
