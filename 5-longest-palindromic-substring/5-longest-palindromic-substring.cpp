class Solution {
    
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int maxi=1;
        int start=0;
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        for(int i=0;i<n;i++)
        {
            dp[i][i]=true;
            if(i+1<n && s[i]==s[i+1])
            {
                dp[i][i+1]=true;
                start=i;
                maxi=2;
            }
        }
        //i=len  j=start  k=end
       for(int i=3;i<=n;i++)
       {
           for(int j=0;j<n-(i-1);j++)
           {
              int k=j+(i-1);
               if(dp[j+1][k-1] && s[j]==s[k])
               {
                   dp[j][k]=true;
                   if(i>maxi)
                   {
                       start=j;
                       maxi=i;
                   }
               }
           }
       }
        return s.substr(start,maxi);
    }
};