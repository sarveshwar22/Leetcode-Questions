/*
class Solution {
    void dfs(vector<vector<int>>& adj,int i, vector<int>& informTime, int &res,int curr)
    {
        curr+=informTime[i];
        res = max(res,curr);
        for(int neigh:adj[i])
        {
            dfs(adj,neigh,informTime,res,curr);
        }
    }
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++)
        {
            if(manager[i]!=-1)
                adj[manager[i]].push_back(i);
        }
        int res = 0;
        int curr = 0;
        dfs(adj,headID,informTime,res,curr);
        return res;
    }
};
*/
class Solution {
    int dfs(int i, vector<int>& manager, vector<int>& informTime)
    {
        if(manager[i]!=-1)
        {
            informTime[i]+=dfs(manager[i],manager,informTime);
            manager[i]=-1;
        }
        return informTime[i];
    }
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int res = 0;
        for(int i=0;i<n;i++)
        {
            res = max(res,dfs(i,manager,informTime));
        }
        return res;
    }
};