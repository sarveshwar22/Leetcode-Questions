class Solution {
    bool isCyclic(int node,vector<vector<int>>&adj,vector<bool>&visited,vector<bool>&vis2)
    {
        if(!visited[node])
        {
            visited[node]=true;
            vis2[node]=true;
            for(auto neigh:adj[node])
            {
                if(!visited[neigh] && isCyclic(neigh,adj,visited,vis2) || vis2[neigh])
                    return true;
            }
        }
        vis2[node]=false;
        return false;
    }
    
    void dfs(int node,vector<vector<int>>&adj,vector<bool>&visited,vector<int>&ans)
    {
        visited[node]=true;
        for(auto n:adj[node])
            if(!visited[n])
                dfs(n,adj,visited,ans);
        ans.push_back(node);
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int>ans;
        vector<bool>visited(numCourses,false);
        vector<bool>vis2(numCourses,false);
        for(int i=0;i<numCourses;i++)
        {
            if(isCyclic(i,adj,visited,vis2))
                return ans;
        }
        
        
        visited=vector<bool>(numCourses,false);
        for(int i=0;i<numCourses;i++)
        {
            if(!visited[i])
                dfs(i,adj,visited,ans);
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
        
    }
};