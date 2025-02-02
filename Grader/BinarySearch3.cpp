#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int tmp;
    while (m--)
    {
        cin >> tmp;

        if (tmp < v[0])
        {
            cout << -1 << '\n';
            continue;
        }

        if (tmp >= v[n - 1])
        {
            // cout << v[n - 1] << '\n';
            cout << n - 1 << '\n';
            continue;
        }

        int left = 0, right = n - 1;
        int mid = (left + right) / 2;
        // cout << "tmp : " << tmp << '\n';
        while (left < right)
        {
            if (tmp < v[mid])
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
            mid = (left + right) / 2;
            // cout << left << " " << right << '\n';
        }
        // if (right == 0)
        // {
        //     cout << 0 << '\n';
        // }
        // else
        // {
        // }

        if (right != 0)
        {
            // cout << v[right - 1] << " " << right - 1 << '\n';
            cout << right - 1 << '\n';
        }
        else
        {
            // cout << v[right] << " " << right << '\n';
            cout << right << '\n';
        }
    }

    return 0;
}