class Solution {
    int RefuelStops(int startfuel,int distTravelled,int target,int next,vector<vector<int>>& stations)
    {
        if(startfuel>=(target-distTravelled))
            return 0;
        if(distTravelled==target)
            return 0;
        if(distTravelled!=target && next==stations.size())
            return INT_MAX-1;
        if(startfuel<(stations[next][0]-distTravelled))
            return INT_MAX-1;
        return min(
RefuelStops(startfuel-stations[next][0]+distTravelled,stations[next][0],target,next+1,stations),
RefuelStops(startfuel-stations[next][0]+distTravelled+stations[next][1],stations[next][0],target,next+1,stations)+1);
        
        
    }
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        //dp[i][j]-farthest location we can get using j refuelling stops among i refueling stops
        //dp[i][0]-startfuel
        
        //refuel-dp[i-1][j-1]>=stations[i][0] ->dp[i][j]=max(dp[i][j],dp[i-1][j-1]+stations[i][1])
        
        //non-refuel-dp[i][j]=max(dp[i][j],dp[i-1][j]) i-1>=j
        int n=stations.size();
        vector<long> dp(n+1,startFuel);
        
        for(int i=0;i<n;i++)
        {
            for(int j=i;j>=0 && dp[j]>=stations[i][0];j--)
            {
                dp[j+1]=max(dp[j+1],dp[j]+stations[i][1]);
                
            }
        }
        
        for(int i=0;i<=n;i++)
        {
            if(dp[i]>=target)
                return i;
        }
        return -1;
    }
};