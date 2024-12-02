#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    long long int n,m, cnt ;
    cin >> n >> m ;
    cnt = n*n;
    // vector<vector<int>>  rooks(m, vector<int>(2));
    unordered_set<int> cols , rows ;
    for(long long int i=0;i<m;i++)
    {
        bool r = false, c= false ;
        long long int col,row, tmp=0;
        cin >> row >> col ;
        if(rows.find(row) == rows.end()) // Not Found 
        {
            cnt -= n ;
            r = true;
            tmp += cols.size();
        }

        if(cols.find(col) == cols.end()) // Not Found
        {
            cnt -= n;
            c = true;
            tmp += rows.size();
        }

        if(r & c)
        {
            tmp += 1;
        }

        rows.insert(row);
        cols.insert(col);

        cnt += tmp ;

        if(cnt < 0)
        {
            cout << 0 << " ";
        }
        else 
        {
            cout << cnt << " ";
        }
    }
}