class Solution {
public:
    // One observation:
    // a^1234567 % k = (a^1234560 % k) * (a^7 % k) % k = (a^123456 % k)^10 % k * (a^7 % k) % k
    int superPow(int a, vector<int>& b) {
        int mod = 1337;
        if(b.empty())return 1;
        int last_digit = b.back();
        b.pop_back();
        return (mod_exp(superPow(a,b),10,mod) * mod_exp(a,last_digit,mod))%mod;
    }

    int mod_exp(int base, int exp,int m)
    {
        if(exp == 1)return base%m;
        if(exp == 0)return 1;
        if(exp%2 == 0)
        {
            int tmp = mod_exp(base,exp/2,m);
            return (tmp*tmp)%m;
        }
        int tmp = mod_exp(base,exp/2,m);
        tmp = (tmp*tmp)%m;
        return (tmp * (base%m))%m;
    }

};