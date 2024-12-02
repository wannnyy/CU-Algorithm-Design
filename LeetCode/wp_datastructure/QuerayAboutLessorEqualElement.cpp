#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n,m ;
    cin >> n >> m ;
    vector<long long> a(n),b(m);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<m;i++) cin >> b[i];

    sort(a.begin(),a.end());

    for(auto x : b)
    {
        auto p = upper_bound(a.begin(),a.end(),x);
        cout << p - a.begin() << " ";
    }





    return  0 ;
}