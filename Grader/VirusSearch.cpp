#include <bits/stdc++.h>

using namespace std;
int n, k;
vector<int> v;

bool solve(int start, int len, int right)
{
    if (len == 2)
    {
        if (right == 1 && v[start] == 0 && v[start + 1] == 1)
            return true;
        if (right == -1 && v[start] == 1 && v[start + 1] == 0)
            return true;
        return false;
    }
    len /= 2;

    if (right == 1)
        return (solve(start, len, 1) || solve(start, len, -1)) && solve(start + len, len, 1);
    return (solve(start + len, len, 1) || solve(start + len, len, -1)) && solve(start, len, -1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    v.resize(pow(2, k));

    while (n--)
    {
        for (int i = 0; i < pow(2, k); i++)
        {
            cin >> v[i];
        }
        if (solve(0, pow(2, k), 1))
        {
            cout << "yes\n";
        }
        else
        {
            cout << "no\n";
        }
    }

    return 0;
}
// bool tmp1, tmp2;
// while (n--)
// {
//     bool ans = true;
//     for (int i = 0; i < pow(2, k - 1); i++)
//     {
//         cin >> tmp1 >> tmp2;

//         if (k == 1 && !(tmp1 == 0 && tmp2 == 1))
//         {
//             // cout << "no\n";
//             ans = false;
//             continue;
//         }

//         ans = ans && (tmp1 xor tmp2);
//     }

//     ans ? cout << "yes\n" : cout << "no\n";
// }