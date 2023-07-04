class Solution {
    void dfs(vector<vector<int>>& rooms, int v, vector<int>& visited)
    {
        if(visited[v])
            return;
        visited[v] = true;
        for(int x:rooms[v])
        {
            dfs(rooms,x,visited);
        }

    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> visited(n,false);
        dfs(rooms,0,visited);
        for(bool v:visited)
            if(!v)
                return false;
        return true;
    }
};