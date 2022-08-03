class Solution {
    int mod = 1e9+7;
    vector<int> factorise(int x)
    {
        vector<int> res;
        if(x>1)
            res.push_back(1);
        for(int i=2;i*i<=x;i++)
        {
            
            if(x%i==0){
                res.push_back(i);
                if(i!=x/i)
                res.push_back(x/i);
            }
        }
        return res;
    }
    // double C(int n,int r)
    // {
    //     long long res =1 ;
    //     if(r>n-r)
    //         r=n-r;
    //     for(int i=0;i<r;i++)
    //     {
    //         res*=(n-i);
    //         res/=(i+1);
    //     }
    //     return res%mod;
    // }
    vector<long long> invFact;
    vector<long long> invNum;
    vector<long long> fact;
    
    long long C(int n,int r)
    {
        if(r<0 || n<r)
            return 0;
        long long res = (((fact[n]%mod)*(invFact[n-r]%mod)%mod)*(invFact[r]%mod))%mod;
        return res;
    }
    
    
    
    public:
    int idealArrays(int n, int maxValue) {
        
        invFact = vector<long long>(1e4+5);
        invNum=vector<long long> (1e4+5);
        fact=vector<long long> (1e4+5);
        invNum[0]=invNum[1]=1;
        invFact[0]=invFact[1]=1;
        fact[0]=fact[1]=1;
        for(int i=2;i<=1e4+4;i++)
        {
            invNum[i] = invNum[mod%i]*(mod-mod/i)%mod;
            invFact[i] = (invNum[i]*invFact[i-1])%mod;
            fact[i] = (i*fact[i-1])%mod;
        }
        
        vector<vector<long long>> dp(maxValue+1,vector<long long>(21,0));
        //dp[i][j] = number of ideal sequences having i as maxElement and j as distinct elements
        for(int i=1;i<=maxValue;i++)
            dp[i][1] = 1;
        for(int i=1;i<=maxValue;i++)
        {
            vector<int> factors = factorise(i);
            //log2(1e4) = 15
            for(int j=2;j<=20;j++)
            {
                for(int k:factors)
                {
                    dp[i][j] += dp[k][j-1];
                    dp[i][j] %= mod;
                }
            }
        }
        // for(auto x:dp)
        // {
        //     for(auto y:x)
        //     {
        //         cout<<y<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        long long ans =0 ;
        for(int i=1;i<=maxValue;i++)
        {
            for(int j=1;j<=min(n,20);j++)
            {
                ans +=C(n-1,j-1)*dp[i][j];
                ans%=mod;
                // cout<<C(n-1,j-1)<<" ";
            }
            // cout<<endl;
        }
        return (int)ans;
    }
};