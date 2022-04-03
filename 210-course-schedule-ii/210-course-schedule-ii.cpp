class Solution {
    vector<vector<int>> buildGraph(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<vector<int>>graph(numCourses);
        for(auto& prereq:prerequisites)
        {
            graph[prereq[1]].push_back(prereq[0]);
        }
        return graph;
    }
    vector<int> computeIndegrees(vector<vector<int>>& graph)
    {
        vector<int> indegrees(graph.size(),0);
        for(auto& adj:graph)
        {
            for(int neigh:adj)
            {
                indegrees[neigh]++;
            }
        }
        return indegrees;
    }
    
    
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        vector<vector<int>> graph=buildGraph(numCourses,prerequisites);
        vector<int> inDegree=computeIndegrees(graph);
        vector<int> order;
        for(int i=0;i<numCourses;i++)
        {
            int j=0;
            for(;j<numCourses;j++)
            {
                if(!inDegree[j])
                {
                    order.push_back(j);
                    break;
                }
            }
            if(j==numCourses)return {};
            inDegree[j]--;
            for(int neigh:graph[j])
            {
                inDegree[neigh]--;
            }
        }
        return order;
    }
};