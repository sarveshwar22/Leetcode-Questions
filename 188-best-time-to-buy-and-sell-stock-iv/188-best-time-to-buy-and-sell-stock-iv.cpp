class Solution {
    int dp[1001][101][2]={};
    int n;
    int dfs(vector<int>& prices,int i,int k,bool buy)
    {
        if(i>=n ||(k==0 && buy))return 0;
        if(dp[i][k][buy])return dp[i][k][buy];
        
        return dp[i][k][buy] = max(dfs(prices,i+1,k,buy),(buy?-1:1)*(prices[i])+dfs(prices,i+1,k-buy,!buy));
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        n=prices.size();
        return dfs(prices,0,k,true);
    }
};