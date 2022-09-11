class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<vector<int>> v;
        for(auto& interval:intervals)
        {
            v.push_back({interval[0],1});
            v.push_back({interval[1]+1,-1});
        }
        sort(v.begin(),v.end());
        int cur=0;
        int res=0;
        for(auto& ele:v)
        {
            cur+=ele[1];
            res=max(res,cur);
        }
        return res;
    }
};