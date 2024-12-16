class Solution {
public:
    int hammingWeight(int n) {
        long long k=1,cnt =0 ;
        for(int i=0;i<31;i++) k *= 2;
        while(true)
        {
            if(n <= 0)break;
            if(n >= k)
            {
                n -= k;
                cnt++;
            }
            k/=2;
        }
        return cnt;


        /*
            # Alternative Solution;
            for i in range(32):
                if (n >> i) & 1:
                    res += 1
        
        */



    }
};