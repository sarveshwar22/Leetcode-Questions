class Solution {
    void dfs(int i,vector<vector<int>>& isConnected,vector<bool>& visited)
    {
        visited[i] = true;
        for(int j=0;j<isConnected.size();j++)
        {
            if(i!=j && isConnected[i][j] && !visited[j])
                dfs(j,isConnected,visited);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n,false);
        int res = 0;
        for(int i=0;i<n;i++)
        {
            if(!visited[i]){
                dfs(i,isConnected,visited);
                res++;
            }
        }
        return res;
    }
};