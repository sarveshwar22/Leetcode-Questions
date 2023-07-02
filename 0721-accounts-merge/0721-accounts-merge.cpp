class Solution {
    vector<int> parent;
    int find(int x)
    {
        if(parent[x]==x)
            return x;
        return find(parent[x]);
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string,int> email;
        parent = vector<int>(n,0);
        for(int i=0;i<n;i++)
        {
            parent[i] = i;
            for(int j=1;j<accounts[i].size();j++)
            {
                if(email.find(accounts[i][j])!=email.end())
                {
                    int f1 = find(i);
                    int f2 = find(email[accounts[i][j]]);
                    parent[f1] = f2;
                }
                else
                {
                    email[accounts[i][j]] = i;
                }
            }
        }

        unordered_map<int,vector<string>> m;
        for(auto it:email)
        {
            int f = find(it.second);
            m[f].push_back(it.first);
        }

        vector<vector<string>> res;
        for(auto it:m)
        {
            vector<string> temp = {accounts[it.first][0]};
            sort(it.second.begin(),it.second.end());
            for(string s:it.second)
                temp.push_back(s);
            res.push_back(temp);
        }
        return res;
    }
};