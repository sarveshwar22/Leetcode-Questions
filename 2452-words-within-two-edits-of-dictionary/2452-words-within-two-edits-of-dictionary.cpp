class Solution {
    bool check(string q,string d)
    {
        int count = 0;
        for(int i=0;i<q.size();i++)
        {
            if(count>2)
                return false;
            if(q[i]!=d[i])
                count++;
        }
        if(count<=2)
            return true;
        return false;
    }
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        for(int i=0;i<queries.size();i++)
        {
            for(int j=0;j<dictionary.size();j++)
            {
                if(check(queries[i],dictionary[j]))
                {
                    ans.push_back(queries[i]);
                    break;
                }
            }
        }
        return ans;
    }
};