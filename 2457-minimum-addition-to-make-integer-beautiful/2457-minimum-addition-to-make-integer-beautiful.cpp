class Solution {
    bool cond(long long n, long long target)
    {
        long long res = 0;
        while(n)
        {
            res+=n%10;
            n/=10;
        }
        return res>target;
    }
public:
    long long makeIntegerBeautiful(long long n, int target) {
        long long temp = n;
        long long base = 1;
        while(cond(n,target))
        {
            n = n/10 + 1;
            base*=10;
        }
        return n*base-temp;
    }
};