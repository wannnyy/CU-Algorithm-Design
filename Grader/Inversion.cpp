#include <iostream>
#include <vector>

using namespace std;



int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    int cnt = 0 ;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    


    // O(n^2) approach
    // for(int i=0;i<n-1;i++)
    // {
    //     for(int j=i+1;j<n;j++)
    //     {
    //         if(v[i]>v[j])cnt++;
    //     }
    // }s

    // cout << cnt;
    return 0;
}