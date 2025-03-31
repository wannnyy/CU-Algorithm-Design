#include <bits/stdc++.h>
using namespace std;

static const int MAXN = 5000;
static const int MAXM = 20000;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    // อ่านความสวยงามของทุ่งหญ้าแต่ละแห่ง
    vector<long long> b(n);
    long long totalBeauty = 0LL;
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        totalBeauty += b[i];
    }

    // อ่านรายการทุ่งหญ้าที่จะเกิดไฟป่าในแต่ละวัน (k วัน)
    vector<int> fireDay(k);
    for (int i = 0; i < k; i++)
    {
        cin >> fireDay[i];
    }

    // สร้าง adjacency list
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int a, b2;
        cin >> a >> b2;
        // a -> b2
        adj[a].push_back(b2);
    }

    // สถานะทุ่งหญ้าที่ถูกเผาแล้ว
    vector<bool> burned(n, false);

    // ประมวลผลในแต่ละวัน
    for (int day = 0; day < k; day++)
    {
        int startGrass = fireDay[day];

        // หากทุ่งหญ้า startGrass ยังไม่โดนเผา => จุดไฟแล้ว BFS/DFS กระจายไฟ
        if (!burned[startGrass])
        {
            // เผาทุ่ง startGrass
            burned[startGrass] = true;
            totalBeauty -= b[startGrass];

            // ใช้ BFS (สามารถเปลี่ยนเป็น DFS ได้เช่นกัน)
            queue<int> Q;
            Q.push(startGrass);

            while (!Q.empty())
            {
                int u = Q.front();
                Q.pop();

                // มองหาเพื่อนบ้านของ u
                for (int v : adj[u])
                {
                    if (!burned[v])
                    {
                        // เผาทุ่ง v
                        burned[v] = true;
                        totalBeauty -= b[v];
                        Q.push(v);
                    }
                }
            }
        }

        // แสดงค่าความสวยงามรวมหลังจบไฟป่าวันนี้
        cout << totalBeauty << " ";
    }
    cout << "\n";

    return 0;
}
