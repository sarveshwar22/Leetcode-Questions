class Solution {
    vector<bool> prime;
    void sieve()
    {
        for(long long i=2;i<=(int)1e6;i++)
        {
            if(prime[i])
            {
                for(long long j=i*i;j<=(int)1e6;j+=i)
                {
                    prime[j] = false;
                }
            }
        }
    }
public:
    vector<int> closestPrimes(int left, int right) {
        
        prime = vector<bool>(1000001,true);
        prime[1] = false;
        sieve();
        int prime1 = -1;
        int prime2 = -1;
        vector<int> primes;
        int d = INT_MAX;
        for(int i=left;i<=right;i++)
        {
            if(prime[i])
            {
                if(primes.size()>=1)
                    d = min(d,i-primes.back());
                primes.push_back(i);
                    
                // if(prime1==-1)
                // {
                //     prime1 = i;
                // }
                // else if(prime2 == -1)
                // {
                //     prime2 = i;
                // }
                // else break;
            }
        }
        if(primes.size()<2)
            return {-1,-1};
        for(int i=1;i<primes.size();i++)
        {
            if(primes[i]-primes[i-1]==d)
                return {primes[i-1],primes[i]};
        }
        return {-1,-1};
    }
};