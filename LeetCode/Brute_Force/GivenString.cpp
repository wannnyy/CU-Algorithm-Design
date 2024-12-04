#include <iostream>
#include <map>

using namespace std;

int main()
{
    int mx = 0 ; 
    string s, mx_s ; 
    cin >> s ;

    map<string,int>  mp ; 

    for(int i=1;i<s.size() + 1;i++)
    {
        //iterate size of i
        for(int j=0;j<=s.size()-i;j++)
        {
            string tmp = "";

            for(int k=0;k<i;k++)
            {
                tmp += s[j+k];
            }
        
            // cout << tmp << '\n';

            if(mp.find(tmp) == mp.end())
            {
                mp[tmp] = 1 ;
            }
            else
            {
                mp[tmp] += 1;
            }

            if(mp[tmp] >= 2)
            {
                mx = mp[tmp];
                mx_s = tmp;
            }
        }
    }
    if(mx >= 2)
    {
        cout << mx_s.size();
    }
    else 
    {
        cout << 0;
    }
}