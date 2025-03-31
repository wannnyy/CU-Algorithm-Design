#include <bits/stdc++.h>
using namespace std;

// Union-Find (Disjoint Set) structure
struct UnionFind
{
    int n;
    vector<int> parent, rank; // or use "size" in place of rank

    UnionFind(int n) : n(n), parent(n), rank(n, 0)
    {
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y)
    {
        int rx = find(x);
        int ry = find(y);
        if (rx == ry)
            return;
        if (rank[rx] < rank[ry])
            swap(rx, ry);
        parent[ry] = rx;
        if (rank[rx] == rank[ry])
            rank[rx]++;
    }
};

static const int UP = 0;
static const int RIGHT = 1;
static const int DOWN = 2;
static const int LEFT = 3;

// road[type] = { dir1, dir2 }
// Index 1-based for type
int road[7][2] = {
    {0, 0},        // dummy index 0, unused
    {LEFT, RIGHT}, // type 1
    {UP, DOWN},    // type 2
    {UP, RIGHT},   // type 3
    {RIGHT, DOWN}, // type 4
    {DOWN, LEFT},  // type 5
    {LEFT, UP}     // type 6
};

// Checks if a given cell type "t" connects in direction "dir"
bool connects(int t, int dir)
{
    return (road[t][0] == dir || road[t][1] == dir);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int R, C;
    cin >> R >> C;
    vector<vector<int>> grid(R, vector<int>(C));
    for (int r = 0; r < R; r++)
    {
        for (int c = 0; c < C; c++)
        {
            cin >> grid[r][c];
        }
    }

    // We will keep all edges in a vector.
    // Then we will union them, and later count edges per component.
    vector<pair<int, int>> edges;
    edges.reserve(R * C * 2); // upper bound

    // Helper to map (r,c) -> single index
    auto idx = [&](int rr, int cc)
    {
        return rr * C + cc;
    };

    // Build edges by checking only UP and LEFT directions
    // to avoid double-counting.
    for (int r = 0; r < R; r++)
    {
        for (int c = 0; c < C; c++)
        {
            int t = grid[r][c];
            // if this cell connects UP, check the cell above
            if (connects(t, UP) && r > 0)
            {
                int aboveType = grid[r - 1][c];
                // We must see if the cell above connects DOWN
                if (connects(aboveType, DOWN))
                {
                    edges.push_back({idx(r, c), idx(r - 1, c)});
                }
            }
            // if this cell connects LEFT, check the cell to the left
            if (connects(t, LEFT) && c > 0)
            {
                int leftType = grid[r][c - 1];
                // We must see if the cell to the left connects RIGHT
                if (connects(leftType, RIGHT))
                {
                    edges.push_back({idx(r, c), idx(r, c - 1)});
                }
            }
        }
    }

    // Create union-find over R*C nodes
    UnionFind uf(R * C);

    // Union all edges
    for (auto &e : edges)
    {
        uf.unite(e.first, e.second);
    }

    // Count size of each component and number of edges
    vector<int> compSize(R * C, 0), compEdges(R * C, 0);

    // Count node membership
    for (int i = 0; i < R * C; i++)
    {
        compSize[uf.find(i)]++;
    }

    // Count edges: each pair belongs to the same component
    for (auto &e : edges)
    {
        int ru = uf.find(e.first);
        // (ru == uf.find(e.second)) after union
        compEdges[ru]++;
    }

    int cycleCount = 0;
    int maxCycleLen = 0;

    // We only look at "root" indices for final results
    // Check if #edges == #nodes in that component
    for (int i = 0; i < R * C; i++)
    {
        if (uf.find(i) == i)
        { // i is a representative
            if (compSize[i] == compEdges[i] && compSize[i] > 0)
            {
                cycleCount++;
                maxCycleLen = max(maxCycleLen, compSize[i]);
            }
        }
    }

    if (cycleCount == 0)
    {
        cout << 0 << "\n";
    }
    else
    {
        cout << cycleCount << " " << maxCycleLen << "\n";
    }

    return 0;
}
