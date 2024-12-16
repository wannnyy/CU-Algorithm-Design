class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> v ;
        int idx1=0,idx2=0;
        // int k  = min(nums1[0],nums2[0]);
        while(true)
        {
            if(idx2 == n & idx1 == m)break;
            if(idx2 == n)
            {
                for(int i=idx1;i<m;i++)
                {
                    v.push_back(nums1[i]);
                }
                break;
            }
            else if(idx1 == m)
            {
                for(int i=idx2;i<n;i++)
                {
                    v.push_back(nums2[i]);
                }
                break;
            }

            if(nums1[idx1] < nums2[idx2])
            {
                v.push_back(nums1[idx1]);
                idx1 += 1;
            }
            else if(nums1[idx1] > nums2[idx2])
            {
                v.push_back(nums2[idx2]);
                idx2 += 1;
            }
            else
            {
                v.push_back(nums2[idx2]);
                v.push_back(nums2[idx2]);
                idx2 += 1;
                idx1 += 1;
            }
        }

        nums1 = v;
    }
};