#include <iostream>
#include <set>
#include <vector>
using namespace std;

set<string> s;

void perm(string &c, int i, int n)
{
    if (i > n)
        return;
    s.insert(c);
    if (c[i] == '0')
    {
        c[i] = '1';
        s.insert(c);
        perm(c, i + 1, n);
        c[i] = '0';
        // perm(c, i + 1, n);
    }
    perm(c,i+1,n);
}

int main()
{
    int n, k;
    cin >> n >> k;

    int left_size = n - k + 1;

    for (int i = 0; i < left_size; i++) // the starter index
    {
        string c;
        int sz = 0;
        for (int j = 0; j < n; j++)
        {
            if (j >= i && sz < k)
            {
                c.append("1");
                sz++;
            }
            else
            {
                c.append("0");
            }
        }
        // cout << c << '\n';
        // for (int j = 0; j < n; j++)
        // {
        //     s.insert(c);
        //     if (c[j] == '0')
        //     {
        //         c[j] = '1';
        //         s.insert(c);
        //         c[j] = '0';
        //     }
        // }
        perm(c,0,n);
    }

    for (auto &x : s)
    {
        cout << x << '\n';
    }

    return 0;
}