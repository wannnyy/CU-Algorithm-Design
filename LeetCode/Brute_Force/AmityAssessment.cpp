#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main()
{
    string s ;
    bool ans = false;
    vector<char> v, p ;
    deque<char> a,b;
    cin >> s;
    v.push_back(s[0]);
    v.push_back(s[1]);

    cin >> s;
    v.push_back(s[1]);
    v.push_back(s[0]);

    cin >> s;
    p.push_back(s[0]);
    p.push_back(s[1]);

    cin >> s;
    p.push_back(s[1]);
    p.push_back(s[0]);

    // iterate clockwise
    for(int i=0;i<6;i++)
    {
        bool tmp = true;
        for(int j=0;j<4;j++)
        {
            if(v[i] != p[(i+j)%4])
            {
                tmp = false;
            }
        }
        if(tmp) ans = true ;
    }

    ans ? cout << "Yes" : cout << "No";
    return 0;
}