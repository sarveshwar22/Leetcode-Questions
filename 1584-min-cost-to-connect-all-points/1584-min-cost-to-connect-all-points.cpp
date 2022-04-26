class Solution {
    int getParent(vector<int>& parents,int i)
    {
        if(parents[i]==i)
            return i;
        return parents[i]=getParent(parents,parents[parents[i]]);
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<int> parent(n);
        iota(parent.begin(),parent.end(),0);
        int ans=0;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(i!=j)
                {
                    pq.push({abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]),i,j});
                }
            }
        }
        
        for(int i=0;i<n-1;)
        {
            vector<int> edge = pq.top();
            pq.pop();
            int p1=getParent(parent,edge[1]);
            int p2=getParent(parent,edge[2]);
            if(p1!=p2)
            {
                ans+=edge[0];
                parent[p1]=p2;
                i++;
            }
        }
        return ans;
        
    }
};