class Solution {
    int m,n;
    bool dfs(vector<vector<bool>>&ocean,int i,int j,vector<vector<int>>& heights)
    {
        if(i<0 || j<0 || i==m || j==n || heights[i][j]==INT_MAX)
            return false;
        if(ocean[i][j])
            return true;
        
        int temp = heights[i][j];
        heights[i][j]=INT_MAX;
        bool flag=false;
        if(i>0 && heights[i-1][j]<=temp)
        {
            flag = flag|| dfs(ocean,i-1,j,heights);
        }if(j>0 && heights[i][j-1]<=temp)
        {
            flag = flag|| dfs(ocean,i,j-1,heights);
        }if(i<m-1 && heights[i+1][j]<=temp)
        {
            flag = flag|| dfs(ocean,i+1,j,heights);
        }if(j<n-1 && heights[i][j+1]<=temp)
        {
            flag = flag|| dfs(ocean,i,j+1,heights);
        }
        ocean[i][j]=flag;
        heights[i][j]=temp;
        return flag;
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m=heights.size();
        n=heights[0].size();
        vector<vector<bool>> pacific(m,vector<bool>(n,false));
        vector<vector<bool>> atlantic(m,vector<bool>(n,false));
        
        for(int i=0;i<m;i++)
        {
            pacific[i][0] = atlantic[i][n-1] = true;
        }
        for(int i=0;i<n;i++)
        {
            
            pacific[0][i]=atlantic[m-1][i]=true;
        }
        
        vector<vector<int>>res;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dfs(pacific,i,j,heights) && dfs(atlantic,i,j,heights))
                {
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }
};