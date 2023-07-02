class Solution {
    vector<int>parent;
    vector<int>rank;
    int find(int x)
    {
        if(parent[x] == x)
            return x;
        return find(parent[x]);
    }
    void Union(int x,int y)
    {
        x = find(x);
        y = find(y);
        if(x==y)
            return;
        if(rank[x]<rank[y])
            parent[x] = y;
        else if(rank[x]>rank[y])
            parent[y] = x;
        else
        {
            parent[y] = x;
            rank[x]++;
        }   
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        parent = vector<int>(10001,0);
        rank = parent;
        for(int i=0;i<10001;i++)
        {
            parent[i] = i;
        }
        int ans = 0;
        vector<int> row_seen(10001,-1);
        vector<int> col_seen(10001,-1);
        int stoneNum = 0;
        for(auto& stone:stones)
        {
            int x = stone[0];
            int y = stone[1];
            if(row_seen[x]==-1)
                row_seen[x] = stoneNum;
            else
                Union(row_seen[x],stoneNum);
            
            if(col_seen[y]==-1)
                col_seen[y] = stoneNum;
            else
                Union(col_seen[y],stoneNum);
            stoneNum++;
        }
        for(int i=0;i<n;i++)
        {
            if(parent[i]==i)
                ans++;
        }
        return n-ans;
    }
};