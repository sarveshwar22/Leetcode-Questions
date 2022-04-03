// BFS solution-

// class Solution {
//     vector<vector<int>> buildGraph(int numCourses, vector<vector<int>>& prerequisites)
//     {
//         vector<vector<int>>graph(numCourses);
//         for(auto& prereq:prerequisites)
//         {
//             graph[prereq[1]].push_back(prereq[0]);
//         }
//         return graph;
//     }
//     vector<int> computeIndegrees(vector<vector<int>>& graph)
//     {
//         vector<int> indegrees(graph.size(),0);
//         for(auto& adj:graph)
//         {
//             for(int neigh:adj)
//             {
//                 indegrees[neigh]++;
//             }
//         }
//         return indegrees;
//     }
    
    
// public:
//     vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
//         vector<int> res;
//         vector<vector<int>> graph=buildGraph(numCourses,prerequisites);
//         vector<int> inDegree=computeIndegrees(graph);
//         vector<int> order;
//         for(int i=0;i<numCourses;i++)
//         {
//             int j=0;
//             for(;j<numCourses;j++)
//             {
//                 if(!inDegree[j])
//                 {
//                     order.push_back(j);
//                     break;
//                 }
//             }
//             if(j==numCourses)return {};
//             inDegree[j]--;
//             for(int neigh:graph[j])
//             {
//                 inDegree[neigh]--;
//             }
//         }
//         return order;
//     }
// };

// DFS solution-
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