#include <bits/stdc++.h>
using namespace std;

static const int MAXN = 100000; // กำหนดลิมิตคร่าว ๆ

vector<int> adj[MAXN];
bool visited[MAXN];

void dfs(int start, int &nodeCount, int &edgeCount, int &maxDeg)
{
    stack<int> st;
    st.push(start);
    visited[start] = true;
    while (!st.empty())
    {
        int u = st.top();
        st.pop();

        // เก็บค่าที่ต้องการ
        nodeCount++;
        int deg = (int)adj[u].size();
        maxDeg = max(maxDeg, deg);
        edgeCount += deg; // แต่ละเส้นจะถูกนับ 2 ครั้ง

        // เดินทางไปเพื่อนบ้าน
        for (int v : adj[u])
        {
            if (!visited[v])
            {
                visited[v] = true;
                st.push(v);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int v, e;
    cin >> v >> e;

    // เคลียร์ข้อมูล
    for (int i = 0; i < v; i++)
    {
        adj[i].clear();
        visited[i] = false;
    }

    // อ่านข้อมูลเส้นเชื่อม
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int answer = 0; // ตัวนับคอมโพเนนต์ที่เป็นกราฟเส้นตรง

    // วนหา connected components
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            int nodeCount = 0;
            int edgeCount = 0; // ระวังนับ 2 เท่าต้องไปหาร 2 ทีหลัง
            int maxDeg = 0;

            dfs(i, nodeCount, edgeCount, maxDeg);

            // แปลง edgeCount ให้เป็นจำนวนเส้นเชื่อมจริงในคอมโพเนนต์
            edgeCount /= 2;

            // ตรวจสอบเงื่อนไข
            if (nodeCount == 1)
            {
                // กรณีมีโหนดเดียว ไม่มีเส้นเชื่อมก็ถือว่าเป็นกราฟเส้นตรง
                answer++;
            }
            else
            {
                // ต้องเป็น tree: edgeCount = nodeCount - 1
                // และไม่มีโหนดใดที่ดีกรีเกิน 2
                if (edgeCount == nodeCount - 1 && maxDeg <= 2)
                {
                    answer++;
                }
            }
        }
    }

    cout << answer << "\n";
    return 0;
}
