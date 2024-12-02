#include <iostream>
// #include <vector>
#include <map>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n ;
    cin >> n;
    // vector<vector<int>> v(n,vector<int>(n,0));
    // vector<int> vv(n);
    int c;
    map<int,int> mp;
    int cnt = 0 ,mx_deg = -1;
    for(int i=0;i<n;i++)
    {

        for(int j=0;j<n;j++)
        {
            cin >> c;
            if(c == 1)
                cnt += 1;
        }
        mx_deg = std::max(mx_deg,cnt);
        mp[cnt] += 1;
        cnt = 0 ;
    }


    for(int i=0;i<=mx_deg;i++)
    {
        cout << mp[i] << " ";
    }

    return 0;
}