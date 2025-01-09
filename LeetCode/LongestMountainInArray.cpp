#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> arr={0,1,2,3,4,5,4,3,2,1,0};
    arr = {2,1,4,7,3,2,5};
    int n = arr.size();
    int cnt = 0 ;
    int l = 0,r = 0 ;
    for(int i=1;i<n-1;i++)
    {
        if(arr[i-1] < arr[i] && arr[i] > arr[i+1])
        {
            l = i-1;
            r = i+1;

            while(l >= 0 && arr[l] < arr[l+1])l-=1;
            while(r < n && arr[r-1] > arr[r]) r += 1;

            cnt = max(cnt,r-l-1);
        }
    }

    cout << cnt;
}

// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int main()
// {
//     vector<int> arr={0,1,2,3,4,5,4,3,2,1,0};
//     arr={2,1,4,7,3,2,5};
//     int n=arr.size();
//     int l = 0,cnt = 0;
//     bool up = true;

//     for(int i=1;i<n;i++)
//     {
//         if(arr[i] > arr[i-1])
//         {
//             if(up == true)
//             {
//                 continue;
//             }
//             else        // This condition is met when the slope is turn from down to up.
//             {
//                 if(i-l >= 3)
//                 {
//                     cnt = max(cnt, i-l);
//                 }
//                 l = i-1;
//                 up = true;
//             }
//         }
//         else if(arr[i] < arr[i-1])
//         {
//             if(up == false)
//             {
//                 if(i == n-1 && i-l >= 3) cnt = max(cnt,i-l+1);
//                 continue;
//             }
//             else
//             {
//                 up = false;
//             }
//         }
//         else
//         {
//             l = i;
//             up = true;
//         }
//     }


//     cout << cnt << " ";



//     return 0;
// }