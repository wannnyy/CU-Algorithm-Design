#include <iostream>
#include <set>

using namespace std;

set<string> s ;
void permu(int n,int i ,int j,int k,string g)
{
    if(n == 0)
    {
        s.insert(g);
        return;
    }
    if(i != 0)
    {
        permu(n-1,i-1,j,k,g.append("A"));
        g.pop_back();
    }
    if(j !=0)
    {
        permu(n-1,i,j-1,k,g.append("B"));
        g.pop_back();

    }
    if(k != 0)
    {
        permu(n-1,i,j,k-1,g.append("C"));
        g.pop_back();

    }
    return ;
}

int main()
{
    int n,i,j,k;

    cin >> n >> i >> j >> k;

    permu(n,i,j,k,"");


    cout << s.size() << '\n';

    for(auto x:s)
    {
        cout<<x<<'\n';
    }

    return 0 ;
}