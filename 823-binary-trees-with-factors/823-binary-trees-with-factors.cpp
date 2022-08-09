class Solution {
    int mod=1e9+7;
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,long long> dp;
        sort(arr.begin(),arr.end());
        long long res=0;
        for(int i=0;i<n;i++)
        {
            dp[arr[i]]=1;
            for(int j=0;j<i;j++)
            {
                if(arr[i]%arr[j]==0)
                {
                    dp[arr[i]]+=dp[arr[j]]*dp[arr[i]/arr[j]];
                    dp[arr[i]]%=mod;
                }
            }
            res+=dp[arr[i]];
            res%=mod;
        }
        return res;
    }
};