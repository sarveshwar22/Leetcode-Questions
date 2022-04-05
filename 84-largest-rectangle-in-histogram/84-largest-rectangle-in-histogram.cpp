class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        heights.push_back(INT_MIN);
        stack<int>s;
        int res=0;
        for(int i=0;i<=n;i++)
        {
            while(!s.empty() && heights[s.top()]>heights[i])
            {
                int top=s.top();
                s.pop();
                if(s.empty())
                {
                    res=max(res,heights[top]*i);
                }
                else
                {
                    res=max(res,heights[top]*(i-1-s.top()));
                }
            }
            s.push(i);
        }
        heights.pop_back();
        return res;
    }
};