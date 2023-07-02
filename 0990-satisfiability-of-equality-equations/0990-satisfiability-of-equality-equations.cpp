class Solution {
    vector<int> parent;
    int find(int x)
    {
        if(parent[x]==x)
            return x;
        return find(parent[x]);
    }
    void Union(int x,int y)
    {
        x = find(x);
        y = find(y);
        if(x==y)
            return;
        parent[x] = y;
    }
    
public:
    bool equationsPossible(vector<string>& equations) {
        parent = vector<int>(26,0);
        for(int i=0;i<26;i++)
            parent[i] = i;
        for(string e:equations)
        {
            if(e[1]=='=')
            {
                Union(e[0]-'a',e[3]-'a');
            }
        }
        for(string e:equations)
        {
            if(e[1]=='!')
            {
                if(find(e[0]-'a')==find(e[3]-'a'))
                    return false;
            }
        }
        return true;
        
    }
};