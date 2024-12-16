class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // O(n) and O(1) space 
        int cnt = 0,k=nums[0];
        for(int i=0;i<nums.size();i++)
        {
            if(k == nums[i])
            {
                cnt +=1 ;
            }
            else
            {
                cnt -= 1;
            }

            if(cnt < 0)
            {
                k = nums[i];
                cnt = 0 ;
            }
        }
        return k;
    }
};