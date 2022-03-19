class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>res;
        res.push_back(intervals[0]);
        int j=0;
        for(int i=1;i<intervals.size();i++)
        {
            if(res[j][1]>=intervals[i][0])
                res[j][1]=max(intervals[i][1],res[j][1]);
            else
            {
                j++;
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};