class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int res=neededTime[0];
        int maxCost = neededTime[0];
        for(int i=1;i<colors.size();i++)
        {
            if(colors[i]!=colors[i-1])
            {
                res-=maxCost;
                maxCost=0;
            }
            res+=neededTime[i];
            maxCost=max(maxCost,neededTime[i]);
        }
        return res-maxCost;
    }
};