class Solution {
    vector<int> parent;
    int provinces;
    int find(int x)
    {
        if(parent[x]==x)
            return x;
        return find(parent[x]);
    }
    void Union(int x,int y,vector<vector<int>>& isConnected)
    {
        x = find(x);
        y = find(y);
        if(x!=y)
        {
            parent[x] = y;
            provinces--;
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        parent = vector<int>(n,0);
        provinces = n;
        for(int i=0;i<n;i++)
            parent[i] = i;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(isConnected[i][j])
                    Union(i,j,isConnected);
            }
        }
        return provinces;
    }
};