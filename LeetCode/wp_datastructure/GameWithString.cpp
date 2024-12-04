#include <iostream>
#include <stack>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.length();
    int cnt = 0;

    stack<char> st;


    for (int i = 0; i < n; i++)
    {
        // cout << s[i];
        if(st.size() == 0)
        {
            st.push(s[i]);
        }
        else if (st.top() == s[i])
        {
            st.pop(); 
            cnt++ ;
        }
        else 
        {
            st.push(s[i]);
        }
    }
    if(cnt%2 == 0)
    {
        cout << "No";
    }
    else 
    {
        cout << "Yes";
    }



}