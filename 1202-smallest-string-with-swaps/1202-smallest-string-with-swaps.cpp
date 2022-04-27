class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
      int n = s.size();
      vector<vector<int>> list(n);
      vector<int> st_ind;
        string out = "",res;
        queue<int> q;
        vector<bool> visited(n,false);
        res= s;
        for(int i=0;i<pairs.size();i++)
        {
            list[pairs[i][0]].push_back(pairs[i][1]);
            list[pairs[i][1]].push_back(pairs[i][0]);
        }
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                q.push(i);
                visited[i] = true;
                out += s[i];
                st_ind.push_back(i);
                while(!q.empty())
                {
                    int tp = q.front();
                    q.pop();
                    for(auto j : list[tp])
                    {
                        if(!visited[j])
                        {
                        q.push(j);
                        st_ind.push_back(j);
                        out += s[j];
                        visited[j] = true;
                        }
                    }
                }
              sort(out.begin(),out.end());
                sort(st_ind.begin(),st_ind.end());
              for(int k=0;k<st_ind.size();k++)
                  res[st_ind[k]] = out[k];
                out = "";
                st_ind.clear();
            }
        }
        return res;
    }
};
