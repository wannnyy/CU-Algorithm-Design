// Nattee's Algorithm
// time: O(nlogn)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int get_sum(vector<int> &s, int stop, int start) {
    return s[start] - s[stop];
}

int solve(vector<int> &v, int start, int stop, vector<int> &s) {
    if( start == stop)
        return v[start];

    int m = (start + stop) / 2;
    
    int left_sum = solve(v, start, m,s);
    int right_sum = solve(v, m+1, stop,s);
    int cross_sum = 0;

    int lsum = 0 ;
    for(int i=0;i<m;i++)
    {
        lsum = max(lsum, get_sum(s, i, m));
    }

    int rsum = 0;
    for(int i=m+1;i<stop;i++)
    {
        rsum = max(rsum, get_sum(s, m+1, i));
    }
    cross_sum = lsum + rsum;

    return max({left_sum, right_sum, cross_sum});
}


int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<int> s;
    s.push_back(0);
    int cnt =0 ;
    for (int i = 0; i < n; i++)
    {
        cnt += v[i];
        s.push_back(cnt);       // start from 0 then v[0]
    }
}
