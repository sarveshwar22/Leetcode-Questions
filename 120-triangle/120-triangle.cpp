class Solution {
    int Total(vector<vector<int>>& triangle,int i,int r,vector<vector<int>>& memo)
    {
        if(r==triangle.size())
            return 0; 
        if(memo[r][i]!=-1)
            return memo[r][i];
        int res=min(Total(triangle,i,r+1,memo),Total(triangle,i+1,r+1,memo))+triangle[r][i];
        return memo[r][i]=res;
    }
    
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        // vector<vector<int>> memo(n,vector<int>(n,-1));
        // return Total(triangle,0,0,memo);
        vector<vector<int>> memo(n,vector<int>(n,0));
        memo[0][0]=triangle[0][0];
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<triangle[i].size();j++)
            {
                if(j==0)
                    memo[i][j]=memo[i-1][j]+triangle[i][j];
                else if(j==triangle[i].size()-1)
                    memo[i][j]=memo[i-1][j-1]+triangle[i][j];
                else 
                    memo[i][j]=min(memo[i-1][j-1],memo[i-1][j])+triangle[i][j];
            }
        }
        
        return *min_element(memo[n-1].begin(),memo[n-1].end());
        
    }
};