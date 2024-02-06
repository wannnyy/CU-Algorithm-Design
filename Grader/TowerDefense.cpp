#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int> &row,int w)
{
    int ans = 2e9;
    

}

int main()
{
    int n, m, k, w, tmp;
    cin >> n >> m >> k >> w;

    vector<int> p(m), h(m), t(k), row(n);

    for (int i = 0; i < m; i++) // monsters' positions
    {
        cin >> p[i];
    }

    for (int i = 0; i < m; i++) // monster healths
    {
        cin >> h[i];
        row[p[i]-1] += h[i];            
    }

    for (int i = 0; i < k; i++) // towers' positionsh
    {
        cin >> t[i];
    }

    













    return 0;
}