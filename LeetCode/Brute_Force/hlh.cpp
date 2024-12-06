#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    long long int r, a ,b;
    cin >> r;

    /*

        From r = x^2 + 2xy + x + 1
        then, r - 1 = x * (x + 2y + 1)

    */

    r -= 1;
    bool ans = false;

    // iterating to x = sqrt(x) is already enough.
    // First it was x <= r/2.
    for (int x = 1; x <= sqrt(r); x++)
    {
        if (r % x == 0)
        {
            if ((r / x - x - 1) % 2 == 0)
            {
                
                long long int y = (r/x -x - 1)/2; 
                    if(y!= 0)
                    {
                        cout << x  << " " << y;
                        ans = true;
                        break;
                    }
            }
        }
    }

    if(!ans)cout<<"NO";
}