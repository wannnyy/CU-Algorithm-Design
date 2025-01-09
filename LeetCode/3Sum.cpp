#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());

    for(int i=0; i<nums.size(); i++)
    {
        // cout << nums[i] << " ";
        vector<int> trip;
        int target = -nums[i];
        if(i>0 && nums[i] == nums[i-1])
        {
            continue;
        }

        if(nums[i] > 0)
        {
            break;
        }

        int left = i + 1;
        int right = nums.size() - 1;

        while (left < right)
        {
            /* code */
            if(nums[left] + nums[right] == target)
            {
                trip.push_back(nums[i]);
                trip.push_back(nums[left]);
                trip.push_back(nums[right]);
                result.push_back(trip);
                // trip.clear();
                left++;
                right--;

                while(left < right && nums[left] == nums[left-1])
                {
                    left++;
                }

                while(left < right && nums[right] == nums[right+1])
                {
                    right--;
                }
            }
            else if(nums[left] + nums[right] < target)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }
    return 0 ;
}