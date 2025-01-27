#include <bits/stdc++.h>

using namespace std;

int n;
vector<long long> v;

bool solve(long long tmp)
{
    bool ans = false;
    for(int i=0;i<n;i++)
    {
        long long target = tmp - v[i]; 
        if(i > 0 && v[i-1] == v[i]) continue;
        int l = i-1, r = i + 1;
        
        while(l >=0 && r<n )
        {
            if(v[l] + v[r] == target)
            {
                ans = true;
                break;
            }
            else if(v[l] + v[r] < target)
            {
                r++;
            }
            else 
            {
                l--;
            }
        }

    }
    return ans;
}

int main()
{
    int m;
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m ;
    long long tmp;
    for(int i=0;i<n;i++)
    {
        cin >> tmp ;
        v.push_back(tmp);
    }

    while(m--)
    {
        cin >> tmp;
        if(solve(tmp))
        {
            cout << "YES" << '\n';
        }
        else 
        {
            cout << "NO" << '\n';
        }
    }




    return 0;
}