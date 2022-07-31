class Solution {
public:
    const static int M=1e9+7, MAXN=1e4+4, p=1e9+7, N=20;
    long long invfact[MAXN+1];
    long long invnum[MAXN+1];
    long long fact[MAXN+1];
    void InverseofNumber(int p){
        invnum[0]=invnum[1]=1;
        for (int i=2;i<=MAXN;i++){
            invnum[i]=invnum[p%i]*(p-p/i)%p;
        }
    }
    // precompute inverse of factorials
    void InverseofFactorial(int p){
        invfact[0]=invfact[1]=1;
        // precompute inverse of natural numbers
        for (int i = 2; i <= MAXN; i++)
            invfact[i]=(invnum[i]*invfact[i-1])%p;
    }
    // calculate factorial of 1 to MAXN
    void factorial(int p){
        fact[0]=1;
        for (int i=1;i<=MAXN;i++) {
            fact[i]=(fact[i-1]*i)% p;
        }
    }
    long long C(long long n,long long r){
        if(n < r || r < 0){
            return 0;
        }
        int res=fact[n];
        res=(M+res*invfact[r])%M;
        res=(M+res*invfact[n-r])%M;
        return res;
    }
    int idealArrays(int n, int maxValue) {
        // there is a observation that the number of distinct numbers in an ideal sequence can not be greater than log(maxValue)
        // 1, 2, 4, 8, ..., this sequence can have the maximum length and it is not more than log(maxValue)+1
        // Hence we can precomute the number of different ideal sequences having k distinct elements
        InverseofNumber(p);
        InverseofFactorial(p);
        factorial(p);
        long long dp[maxValue+1][N];
        // dp(i,j) represents the number of ideal sequences with i as the last value and having j distinct elements 
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=maxValue;i++){
            // the number of sequences with length 1 with last value being i is exactly 1
            dp[i][1]=1;
        }
        // factorization
        auto factorize = [&](int x){
            // take all factors except the number itself
            vector<int> res;
            if(x > 1){
                res.push_back(1);
            }
            for(int i=2;i*i<=x;i++){
                if(x%i == 0){
                    res.push_back(i);
                    if(i != x/i){
                        res.push_back(x/i);
                    }
                }
            }
            return res;
        };
        for(int i=1;i<=maxValue;i++){
            vector<int> fact=factorize(i);
            for(int j=2;j<N;j++){
                for(int x: fact){
                    // the last element i must have been preceeded by the one of it's factors
                    // so the transition is number of sequences with length j and last element i is the sum
                    // of all sequences with length j-1 and last element as factor of i 
                    dp[i][j]+=dp[x][j-1];
                    dp[i][j]%=M;
                }
            }
        }
        long long ans=0;
        for(int i=1;i<=maxValue;i++){
            long long tmp=0;
            // how many distinct k length sequences are possible with last element as i
            for(int k=1;k<=min(n,(int)(N-1));k++){
                // Now the number of such sequences is equal to the number of solutions of the equation below
                // x1+x2+...+xk = n
                // where each of x1, x2,..., xk >= 1
                // hence, subtract 1 from each of the variable and the resulting equation is
                // x1'+x2'+...+xk' = n-k
                // the number of ideal sequences with last element as i and having k distinct elements is thus the number
                // of solution of the above equation (C(n-k+k-1,k-1)) multiplied by dp[i][k]
                long long add=C(n-1,k-1);
                tmp+=add*dp[i][k];
                tmp%=M;
            }
            ans+=tmp;
            ans%=M;
        }
        return (int)ans;
    }
};