class Solution {
    vector<int> parent;
    vector<int> rank;
    int find(int x)
    {
        if(parent[x] == x)
            return x;
        return find(parent[x]);
    }
    bool Union(int x,int y)
    {
        x = find(x);
        y = find(y);
        if(x==y)
            return true;
        if(rank[x]>rank[y])
        {
            parent[y] = x;
        }
        else if(rank[x]<rank[y])
        {
            parent[x] = y;
        }
        else
        {
            parent[x] = y;
            rank[y]++;
        }
        return false;
        
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        parent = vector<int>(n,0);
        rank = parent;
        for(int i=0;i<n;i++)
            parent[i] = i;
        int numExtraConnections = 0;
        for(vector<int>& connection:connections)
        {
            if(Union(connection[0],connection[1]))
            {
                numExtraConnections++;
            }
        }
        int extraComputer = 0;
        for(int i=0;i<n;i++)
        {
            if(parent[i]==i)
                extraComputer++;
        }
        return extraComputer-1>numExtraConnections ? -1:extraComputer-1;
        
    }
};