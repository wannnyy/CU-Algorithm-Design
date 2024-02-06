#include <iostream>
#include <vector>
using namespace std;

bool check(vector<int> &v, vector<int> &con)
{
    bool ans = true;
    int n = v.size(), m = con.size();
    // 0 2 4 6
    for (int i = 0; i < m; i += 2)
    {
        int x1 = con[i], x2 = con[i + 1], c1, c2;
        for (int i = 0; i < n; i++)
        {
            if (x1 == v[i])
            {
                c1 = i;
            }
            if (x2 == v[i])
            {
                c2 = i;
            }
        }

        if (c1 > c2)
            ans = false;
    }
    return ans;
}

bool check2(vector<bool> used, vector<int> con)
{
    bool ans = true;
    int n = used.size(), m = con.size();

    for (int i = 0; i < m; i += 2)
    {
        int c1 = con[i], c2 = con[i + 1];
        if (used[c1] == false && used[c2] == true)
        {
            ans = false;
            break;
        }
    }

    return ans;
}

void perm(int n, vector<int> &sol, int len, vector<bool> &used, vector<int> &con)
{
    if (len < n)
    {
        for (int i = 0; i < n; i++) // We can check this instead
        {
            if (used[i] == false && check2(used,con))
            {
                used[i] = true;
                sol[len] = i;
                perm(n, sol, len + 1, used, con);
                used[i] = false;
            }
        }
    }
    else if (check(sol, con))
    {
        for (auto &x : sol)
            cout << x << " ";
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> tp(m * 2), N(n);
    vector<bool> used(n, false);
    for (int i = 0; i < n; i++)
    {
        N[i] = i;
    }
    for (int i = 0; i < m * 2; i += 2)
    {
        cin >> tp[i] >> tp[i + 1];
    }
    perm(n, N, 0, used, tp);
    return 0;
}