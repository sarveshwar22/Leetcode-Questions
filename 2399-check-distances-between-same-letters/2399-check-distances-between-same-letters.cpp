class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        unordered_set<int> se;
        unordered_map<int,int> m;
        for(int i=0;i<s.size();i++)
        {
            if(se.find(s[i]-'a')!=se.end())
            {
                int dist =i- m[s[i]-'a']-1;
                if(dist!=distance[s[i]-'a'])
                    return false;
            }
            else
            {
                se.insert(s[i]-'a');
                m[s[i]-'a']=i;
            }
        }
        return true;
        
    }
};