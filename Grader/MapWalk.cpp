#include <iostream>
#include <vector>
#include <set>

using namespace std;

set<string> S ;

void recur(vector<vector<int>> &v, string s,int x, int y,bool down, bool free)
{
    if(x == v.size() - 1 && y == v[0].size() - 1)
    {
        S.insert(s);
        return;
    }
    if(v[x][y] == 1 )return;
    if(x < v.size() && y < v[0].size())
    {
        if(y + 1 < v[0].size() && v[x][y+1] != 1)
        {
            recur(v,s.append("A"),x,y+1,down,true);
            s.pop_back();
        }
        if(x + 1 < v.size() && (down || free) && v[x+1][y] != 1)
        {
            recur(v,s.append("B"),x+1,y,true,false);
            s.pop_back();
        }
        if(x-1 >=0  && (!down || free) && v[x-1][y] != 1)
        {
            recur(v,s.append("C"),x-1,y,false,false);
        }
    }
    return;
}

int main()
{
    int r, c;
    cin >> r >> c; 
    vector<vector<int>> v(r,vector<int>(c));
    // cout << v.size() << v[0].size();
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin >> v[i][j];
            // cout << v[i][j];
        }
    }

    recur(v,"",0,0,true,false);

    for(auto x :S)
    {
        cout << x << "\n";
    }
    cout << "DONE";
    return 0;
}