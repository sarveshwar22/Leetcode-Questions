class Solution {
    bool isPossible(long long x,vector<long long>& stationPowers,int r,int k,int n)
    {
        vector<long long> extraPower(n+1);
        
        for(int i=0;i<n;i++)
        {
            extraPower[i]+=(i>=1)?extraPower[i-1]:0;
            long long curr = stationPowers[i]+extraPower[i];
            long long req = max(0LL,x-curr);
            if(req==0)
                continue;
            if(req>k)
                return false;
            k-=req;
            extraPower[i]+=req;
            extraPower[min(n,i+2*r+1)] -=req;
        }
        return true;
    }
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        vector<long long> stationPowers(n+1);
        for(int i=0;i<n;i++)
        {
            stationPowers[max(0,i-r)] +=stations[i];
            stationPowers[min(n,i+r+1)] -= stations[i];
        }
        for(int i=1;i<=n;i++)
            stationPowers[i]+=stationPowers[i-1];
        
        long long left=0,right=1e11;
        while(left<right)
        {
            long long mid = (left+right)>>1;
            if(isPossible(mid+1,stationPowers,r,k,n))
            {
                left = mid+1;
            }
            else
                right=mid;
        }
        return left;
    }
};