// #include <iostream>
#include <bits/stdc++.h>

using namespace std;
int n , m;
int mn = 21;

vector<bitset<1000>> student;
bitset<1000> current;

void recur(int cnt,int dpt,int idx)
{
    if(cnt == n)
    {
        mn = min(mn,dpt);
    }

    if(dpt >= mn || cnt == n)return;

    bitset<1000> cur = current;
    for(int i=idx;i<m;i++)
    {
        current = current | student[i];
        cnt = current.count();
        recur(cnt,dpt + 1, idx + 1);
        cnt = cur.count();
        current = cur;
    }
}

int main()
{
    cin >> n >> m ;
    student.resize(m);
    for(int i=0;i<m;i++)
    {
        int tmp;
        cin >> tmp ;
        for(int j=0;j<tmp;j++)
        {
            int c ;
            cin >> c;
            student[i][c]  = true;
        }
    }
    recur(0,0,0);
    cout <<mn;
}