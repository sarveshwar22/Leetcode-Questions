class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        unordered_map<double,int> freq;
        int res=0;
        for(int i=0;i<n;i++)
        {
            int currMax=0;
            for(int j=i+1;j<n;j++)
            {
                double slope=(points[j][0]==points[i][0])?(double)INT_MAX:(float(points[j][1]-points[i][1])/float(points[j][0]-points[i][0]));
                freq[slope]++;
                currMax=max(currMax,freq[slope]);
            }
            freq.clear();
            res=max(res,currMax);
        }
        return res+1;
    }
};