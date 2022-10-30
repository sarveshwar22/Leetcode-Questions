class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) 
    {
        unordered_map<string,long long> totalViews,popular;
        vector<vector<string>> res;
        long long maxViews = 0;
        int n=ids.size();
        for(int i=0;i<n;i++)
        {
            maxViews = max(maxViews,totalViews[creators[i]]+=views[i]);
            auto it = popular.find(creators[i]);
            if(it == popular.end())
            {
                popular[creators[i]] = i;
            }
            else if(views[i] >= views[it->second])
            {
                if(views[i]==views[it->second])
                    it->second = ids[i]<ids[it->second] ? i:it->second;
                else 
                    it->second = i;
            }
        }
        
        for(auto& [creator,totViews]:totalViews)
        {
            if(totViews==maxViews)
            {
                res.push_back({creator,ids[popular[creator]]});
            }
        }
        return res;
        
    }
};