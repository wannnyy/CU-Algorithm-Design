#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> nums ={5,1,3,5,10,7,4,9,2,8};
    int result =  1e6 + 1;
        int tmp = 0,cnt = 0;
        int target = 15;
        bool ans = false;
        for(int i=0;i<nums.size();i++)
        {
            // if(tmp <= nums[i] && ans)
            // {
            //     cnt = 1;
            //     tmp = nums[i];
            //     cout << tmp ;
            // }
            // else
            // {
                cnt += 1;
                tmp += nums[i];
                if(tmp >= target)
                {
                    ans = true;
                    int tp = tmp,c = cnt;
                    for(int j=0;j<c-1;j++)
                    {
                        tp = tp - nums[i-c+j+1];
                        if(tp>=target)cnt--;
                        else
                        {
                            tp += nums[i-c+j+1];
                            break;
                        }
                    }
                    tmp = tp;
                    result = min(result,cnt);
                    cout << "i: " << i << '\n';
                    cout << tmp << " " << result << '\n';

                } 
        }
        std::cout << result << " ";
        if(ans) std::cout << result;
        else std::cout << 0;
    return 0;
}