#include <iostream>
#include <vector>
#include <set>
using namespace std;

int find(vector<int> &parent, int x)
{
    if (parent[x] != x)
        parent[x] = find(parent, parent[x]); // Path compression
    return parent[x];
}

void unionNodes(vector<int> &parent, int a, int b)
{
    int rootA = find(parent, a);
    int rootB = find(parent, b);
    if (rootA != rootB)
        parent[rootB] = rootA; // Merge the sets
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int v, e;
    cin >> v >> e;

    // Initialize parent for each node (nodes are numbered 1 to v)
    vector<int> parent(v + 1);
    for (int i = 1; i <= v; ++i)
        parent[i] = i;

    // Process each edge
    for (int i = 0; i < e; ++i)
    {
        int a, b;
        cin >> a >> b;
        unionNodes(parent, a, b);
    }

    // Count distinct connected components by finding unique roots
    set<int> components;
    for (int i = 1; i <= v; ++i)
        components.insert(find(parent, i));

    cout << components.size() << "\n";
    return 0;
}
