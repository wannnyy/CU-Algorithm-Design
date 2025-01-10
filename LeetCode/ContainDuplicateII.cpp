#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main()
{
    // Map implementation.
    vector<int> nums = {1,2,3,4,1};
    int k =  3;
    bool result = false; 
        map<int,int> m ;
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(nums[i]) == m.end())
            {
                m[nums[i]] = i;
            }
            else
            {
                if(abs(i - m[nums[i]]) <= k )result = true;
                m[nums[i]] = i;
            }
        }
    cout << "result from Map Implementation: "  << result;

    cout << " \n------------------------------------------\n";


    set<int> s ;
    result = false;
    for(int i=0;i<nums.size();i++)
    {
        if(s.find(nums[i]) != s.end())result=true;
        else
        {
            s.insert(nums[i]);
        }
        if(s.size() > k)s.erase(nums[i-k]);
    }
    cout << "result from set Implementation: "  << result;
    return 0 ;
}