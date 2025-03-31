#include <bits/stdc++.h>

using namespace std;

int find(vector<int> &parent, int x)
{
    if (parent[x] != x)
    {
        parent[x] = find(parent, parent[x]);
    }
    return parent[x];
}

void unionNode(vector<int> &parent, int a, int b)
{
    int rootA = find(parent, a);
    int rootB = find(parent, b);
    if (rootA != rootB)
    {
        parent[rootB] = rootA;
    }
}

int main()
{
    int v, e;
    cin >> v >> e;
    vector<int> parent(v + 1);
    for (int i = 1; i <= v; i++)
    {
        parent[i] = i;
    }

    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        unionNode(parent, a, b);
    }

    set<int> components;
    for (int i = 1; i <= v; i++)
    {
        components.insert(find(parent, i));
    }

    cout << components.size() << '\n';

    return 0;
}