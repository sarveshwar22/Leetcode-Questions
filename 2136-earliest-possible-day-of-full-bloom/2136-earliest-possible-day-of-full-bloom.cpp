class Solution {
    static bool cmp(pair<int,int> &v1,pair<int,int> &v2)
    {
        return v1.first>v2.first;
    }
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>> vp;
        int n=plantTime.size();
        
        for(int i=0;i<n;i++)
        {
            vp.push_back({growTime[i],plantTime[i]});
        }
        sort(vp.begin(),vp.end(),cmp);
        
        int days = 0;
        int ans = 0;
        
        for(int i=0;i<n;i++)
        {
            days+=vp[i].second;
            ans = max(ans,days+vp[i].first);
        }
        return ans;
    }
};