#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> v(n), sf(n), sb(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        sf[i] = v[i];
        sb[i] = v[i];
    }


    // Second try , two-pointers
    int st = 0, end = n-1 ;

    for(int i=1;i<n;i++)
    {
        sf[i] += sf[i-1];
    }

    for(int i=n-2;i>=0;i--)
    {
        sb[i] += sb[i+1];
    }
    long long ans = 0;
    while(st < end)
    {
        if(sf[st] == sb[end]){
            ans = max(ans,sf[st]);
            st += 1;
        }
        else if (sf[st] < sb[end]){
            st += 1;
        }
        else if (sf[st] > sb[end]){
            end -= 1;
        }
    }
    cout << ans;

    // First try
    // // for(auto x : sf)
    // // {
    // //     cout << x <<" ";
    // // }
    // // cout << '\n';

    // // for(auto x : sb)
    // // {
    // //     cout << x << " ";
    // // }
    // // cout << '\n';
    // int ans = 0;
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=n-1;j>i;j--)
    //     {
    //         if(sf[i] == sb[j])
    //         {
    //             ans = max(ans,sb[j]);
    //             break;
    //         }
    //     }
    // }
    // cout << ans;

}


