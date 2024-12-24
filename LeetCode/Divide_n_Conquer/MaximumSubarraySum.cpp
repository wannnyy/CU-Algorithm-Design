class Solution {
public:
    // Kadane's algorithm.
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int cnt = nums[0],glb_max = nums[0] ;
        for(int i=1;i<n;i++){
            cnt += nums[i];
            if(cnt < nums[i])
            {
                cnt = nums[i];
            }
            if(cnt >= glb_max)
            {
                glb_max = cnt;
            }
        }
        return glb_max;
    }

    // Nattee's Algorithm.
    // Divide & Conquer Approach.



};