#include <iostream>
#include <set>

using namespace std;

set<string> s;

void permu(int sz, int mx_sz, int one_cnt, int one_mx, string &c)
{
    string ss = c;
    if (sz > mx_sz || one_cnt > one_mx)
        return;
    if (sz == mx_sz && one_cnt == one_mx)
    {
        // s.insert(c);
        cout << c << '\n';
        return;
    }

    permu(sz + 1, mx_sz, one_cnt + 1, one_mx, c.append("1"));
    permu(sz + 1, mx_sz, one_cnt, one_mx, ss.append("0"));
}

int main()
{
    int b, a;
    cin >> b >> a;
    // a is every possible choice

    string c = "";
    permu(0, a, 0, b, c);

    // for (auto &x : s)
    // {
    //     cout << x << '\n';
    // }

    return 0;
}