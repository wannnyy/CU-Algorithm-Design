#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> arr={0,1,2,3,4,5,4,3,2,1,0};
    int n=arr.size();
    int l = 0,cnt = 0;
    bool up = true;

    for(int i=1;i<n;i++)
    {
        if(arr[i] > arr[i-1])
        {
            if(up == true)
            {
                continue;
            }
            else
            {
                if(i-l >= 3)
                {
                    cnt = max(cnt, i-l);
                }
                l = i-1;
                up = true;
            }
        }
        else if(arr[i] < arr[i-1])
        {
            if(up == false)
            {
                continue;
            }
            else
            {
                up = false;
            }
        }
        else
        {
            l = i;
            up = true;
        }
        // cout << i -l  << endl;
    }


    cout << cnt << " ";



    return 0;
}