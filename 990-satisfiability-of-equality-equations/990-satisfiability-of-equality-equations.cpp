class Solution {
    int adj[26];
    int find(int x)
    {
        if(x!=adj[x])
        {
            adj[x]=find(adj[x]);
        }
        return adj[x];
    }
public:
    bool equationsPossible(vector<string>& equations) {
        for(int i=0;i<26;i++)
        {
            adj[i]=i;
            
        }
        for(string s:equations)
        {
            if(s[1]=='=')
            {
                adj[find(s[0]-'a')]= find(s[3]-'a');
            }
        }
        for(string s:equations)
        {
            if(s[1]=='!' && find(s[0]-'a')==find(s[3]-'a'))
            {
                return false;
            }
        }
        return true;
    }
};