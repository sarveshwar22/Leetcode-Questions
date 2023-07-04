class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses);
        vector<int> order;
        for(int i=0;i<pre.size();i++)
        {
            adj[pre[i][1]].push_back(pre[i][0]);
            indegree[pre[i][0]]++;
        }
        
        queue<int> q;
        for(int i=0;i<numCourses;i++)
        {
            if(!indegree[i])
                q.push(i);
        }
        int count = 0;
        while(!q.empty())
        {
            int front = q.front();
            q.pop();
            order.push_back(front);
            count++;
            for(int neigh:adj[front])
            {
                indegree[neigh]--;
                if(indegree[neigh]==0)
                    q.push(neigh);
            }
        }
        if(count!=numCourses)
            return {};
        return order;
        
    }
};